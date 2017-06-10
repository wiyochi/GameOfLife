#include "input.h"

std::string firstInput()
{
	std::string userInput;
	do {
		std::cout << "GameOfLife: ";
		std::getline(std::cin, userInput);
	} while (userInput.size() < 1);
	return userInput;
}

void golInput()
{
	int width(0), height(0);
	int i;
	bool error(false);
	std::string userInput;
	std::string tmp;
	std::string gol = "gol";

	while (tmp != gol)
	{
		if (error)
		{
			tmp.push_back(userInput[i]);
			if (tmp == "help")
				help();
			else
				std::cout << "No instance of the \"Game of life\" in progress (type \"gol <width> <height> \" or \"help\"" << std::endl;
		}

		tmp = "";
		i = 0;
		userInput = firstInput();
		for (i = 0; i < 3; i++) {
			tmp.push_back(userInput[i]);
		}

		if (tmp != gol)
			error = true;
	}
	i++;
	try {
		width = argInt(userInput, i, &i);
		height = argInt(userInput, i, &i);
	}
	catch (std::invalid_argument e){
		std::cerr << e.what() << std::endl;
		golInput();
	}

	waitEventMainThread(userInput, width, height);
}

void waitEventMainThread(std::string golIn, int width, int height)
{
	Window* mainWindow = new Window("Game of life", 100, 100, width + 2, height + 2);
	SDL_Renderer* renderer = mainWindow->getRenderer();
	CellArray* cellTab = new CellArray(4, 4, width, height, 30, 30);
	cellTab->createShip(2, 2);
	cellTab->randomize(20);

	std::thread inputs(selectInput, cellTab, mainWindow);
	launchWindow(mainWindow, renderer, cellTab);

	inputs.join();
}

void selectInput(CellArray* cellTab, Window* mainWindow)
{
	if (!mainWindow->isOpen())
		golInput();

	std::string userInput = firstInput();
	std::string tmp = "";
	int i;
	int newSpeed;
	int randomPercent;
	int x, y;

	if (userInput.size() < 4)
		selectInput(cellTab, mainWindow);

	for (i = 0; i < 4; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "stop")
	{
		cellTab->stop();
		selectInput(cellTab, mainWindow);
	}
	else if (tmp == "play")
	{
		cellTab->play();
		selectInput(cellTab, mainWindow);
	}
	else if (tmp == "help")
	{
		help();
		selectInput(cellTab, mainWindow);
	}
	
	if (userInput.size() < 5)
		selectInput(cellTab, mainWindow);

	tmp = "";
	for (i = 0; i < 5; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "speed")
	{
		i++;
		try {
			newSpeed = argInt(userInput, i, &i);
		}
		catch (std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
			selectInput(cellTab, mainWindow);
		}
		cellTab->changeSpeed(newSpeed*-20 + 2000);
		selectInput(cellTab, mainWindow);
	}
	else if (tmp == "clear")
	{
		cellTab->clear();
		selectInput(cellTab, mainWindow);
	}
	else if (tmp == "close")
	{
		mainWindow->close();
		golInput();
	}

	if (userInput.size() < 6)
		selectInput(cellTab, mainWindow);

	tmp = "";
	for (i = 0; i < 6; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "random")
	{
		i++;
		try {
			randomPercent = argInt(userInput, i, &i);
		}
		catch (std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
			selectInput(cellTab, mainWindow);
		}
		cellTab->randomize(randomPercent);
		selectInput(cellTab, mainWindow);
	}

	if (userInput.size() < 10)
		selectInput(cellTab, mainWindow);

	tmp = "";
	for (i = 0; i < 10; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "createShip")
	{
		i++;
		try {
			x = argInt(userInput, i, &i);
			y = argInt(userInput, i, &i);
		}
		catch (std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
			selectInput(cellTab, mainWindow);
		}
		cellTab->createShip(x, y);
		selectInput(cellTab, mainWindow);
	}
	selectInput(cellTab, mainWindow);
}

int argInt(std::string str, int i, int* adI)
{
	std::string tmp;
	while ((i > str.size()-1 || str[i] != ' ') && str[i] > 47 && str[i] < 58)
	{
		tmp.push_back(str[i]);
		i++;
	}

	if (i > str.size()-1 || str[i] == ' ')
	{
		*adI = i + 1;
		return std::stoi(tmp);
	}
	else
		throw std::invalid_argument("ArgError: string can't be convert");
}

void help()
{
	std::cout << "Available orders with GoL: " << std::endl;
	std::cout << " - gol <width> <height>" << std::endl;
	std::cout << " - speed <new speed int (in millisecond)>" << std::endl;
	std::cout << " - random <percent int>" << std::endl;
	std::cout << " - clear" << std::endl;
	std::cout << " - stop" << std::endl;
	std::cout << " - play" << std::endl;
	std::cout << " - createShip <x> <y>" << std::endl;
	std::cout << " - close" << std::endl;
}