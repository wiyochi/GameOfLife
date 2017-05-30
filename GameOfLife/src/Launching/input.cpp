#include "input.h"

std::string firstInput()
{
	std::string userInput;
	do {
		std::cout << "GameOfLife: ";
		std::cin >> userInput;
	} while (userInput != "new" || userInput != "speed" || userInput != "stop" || userInput != "play");
	return userInput;
}

void selectInput()
{
	std::string userInput = firstInput();
	int width(0), height(0);

	if (userInput == "new")
	{
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