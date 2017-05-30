#include "input.h"

const char* firstInput()
{
	char* userInput;
	std::cin >> userInput;
	return userInput;
}

void windowInput(int *windowWidth, int *windowHeight)
{
	do {
		std::cout << "Window's size: ";
		std::cin >> *windowWidth, *windowHeight;
		std::cout << std::endl;
	} while (*windowWidth < 300 || *windowWidth > 2000 || *windowHeight < 300 || *windowHeight > 1500);
}

void selectInput()
{
	const char* userInput = firstInput();
	int width(0), height(0);

	if (userInput == "new")
	{
		windowInput(&width, &height);
	}
	else if (userInput == "speed")
	{

	}
	else if (userInput == "stop")
	{

	}
	else if (userInput == "play")
	{

	}
}