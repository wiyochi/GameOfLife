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
	std::string userInput = firstInput();
	std::string tmp = { userInput[0], userInput[1], userInput[2], userInput[3] };

	if (tmp == "gol ")
	{
		int i = 4;
		while (userInput[i] != ' ')
		{
			tmp = { userInput[i] };
		}
		windowInput(&width, &height);
	}
	else if (userInput == "speed")
	{
		int speed = speedInput();
	}
	else if (userInput == "stop")
	{

	}
	else if (userInput == "play")
	{

	}
}

void windowInput(int *windowWidth, int *windowHeight)
{
	do {
		std::cout << "Window's size (w/h): ";
		std::cin >> *windowWidth, *windowHeight;
		std::cout << std::endl;
	} while (*windowWidth < 300 || *windowWidth > 2000 || *windowHeight < 300 || *windowHeight > 1500);
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