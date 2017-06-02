#include "input.h"

std::string firstInput()
{
	std::string userInput;
	std::cout << "GameOfLife: ";
	std::cin >> userInput;
	return userInput;
}

void golInput()
{
	int width(0), height(0);
	int i;
	std::string userInput;
	std::string tmp = "";

	while (tmp != "gol ")
	{
		i = 0;
		userInput = firstInput();
		for (i = 0; i < 4; i++)
			tmp.push_back(userInput[i]);
	}
	try {
		width = argInt(userInput, i, &i);
		height = argInt(userInput, i, &i);
	}
	catch (std::invalid_argument e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "TEST" << std::endl;
	selectInput(userInput, width, height);
}

void selectInput(std::string golIn, int width, int height)
{
	Window* mainWindow = new Window("Game of life", 100, 100, width + 2, height + 2);
	SDL_Renderer* renderer = mainWindow->getRenderer();
	CellArray* cellTab = new CellArray(4, 4, width, height, 30, 30);
	cellTab->createShip(2, 2);
	cellTab->randomize(20);

	std::thread gameOfLife(launchWindow, mainWindow, renderer, cellTab);

	std::string userInput = golIn;
	std::string tmp;
	int i;
	int newSpeed;
	int randomPercent;
	int x, y;

	for (i = 0; i < 4; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "stop")
	{
		cellTab->stop();
		selectInput(firstInput(), width, height);
	}
	else if (tmp == "play")
	{
		cellTab->play();
		selectInput(firstInput(), width, height);
	}
	else if (tmp == "help")
	{
		std::cout << "Available orders with GoL: " << std::endl;
		std::cout << " - speed <new speed int>" << std::endl;
		std::cout << " - random <percent int>" << std::endl;
		std::cout << " - clear" << std::endl;
		std::cout << " - stop" << std::endl;
		std::cout << " - play" << std::endl;
		std::cout << " - createShip <x> <y>" << std::endl;
		std::cout << " - close" << std::endl;
		selectInput(firstInput(), width, height);
	}

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
		}
		cellTab->changeSpeed(newSpeed);
		selectInput(firstInput(), width, height);
	}
	else if (tmp == "clear")
	{
		cellTab->clear();
		selectInput(firstInput(), width, height);
	}
	else if (tmp == "close")
	{
		golInput();
	}

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
		}
		cellTab->randomize(randomPercent);
		selectInput(firstInput(), width, height);
	}

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
		}
		cellTab->createShip(x, y);
		selectInput(firstInput(), width, height);
	}
}

void windowInput(std::string str, int* w, int* h)
{
	int i = 4;
	try
	{
		*w = argInt(str, i, &i);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		*h = argInt(str, i, &i);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int speedInput()
{
	int speed;
	do {
		std::cout << "Speed: ";
		std::cin >> speed;
		std::cout << std::endl;
	} while (speed < 0 || speed > 100);
	return speed;
}

int argInt(std::string str, int i, int* adI)
{
	std::string tmp;
	while (str[i] != ' ' && str[i] > 47 && str[i] < 58)
	{
		tmp.push_back(str[i]);
		i++;
	}

	if (str[i] == ' ')
	{
		*adI = i + 1;
		return std::stoi(tmp);
	}
	else
		throw std::invalid_argument("ArgError: string can't be convert");
}