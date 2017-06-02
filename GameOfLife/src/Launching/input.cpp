#include "input.h"

std::string firstInput()
{
	std::string userInput;
	std::cout << "GameOfLife: ";
	std::cin >> userInput;
	return userInput;
}

void selectInput()
{
	int width(0), height(0);
	Window* mainWindow;
	SDL_Renderer* renderer;
	CellArray* cellTab;

	bool on(false);
	std::string userInput = firstInput();
	std::string tmp;

	for (int i = 0; i < 4; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "gol ")
	{
		if (!on)
		{
			windowInput(userInput, &width, &height);
			std::thread gameOfLife(launchWindow, width, height, mainWindow, renderer, cellTab);
			on = !on;
		}
		else
		{
			std::cout << "An instance is already in progress" << std::endl;
		}
		selectInput();
	}

	for (int i = 0; i < 5; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "stop ")
	{
		cellTab->stop();
	}
	else if (tmp == "play ")
	{
		cellTab->stop();
	}
	else if (tmp == "help ")
	{

	}

	for (int i = 0; i < 6; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "speed ")
	{

	}
	else if (tmp == "clear ")
	{
		cellTab->clear();
	}
	else if (tmp == "close ")
	{

	}

	for (int i = 0; i < 7; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "random ")
	{

	}

	for (int i = 0; i < 11; i++)
		tmp.push_back(userInput[i]);

	if (tmp == "createShip ")
	{

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