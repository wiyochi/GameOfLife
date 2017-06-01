#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "SDL.h"
#include "Window/Window.h"
#include "Cell/Cell.h"
#include "Cell/CellArray.h"
#include "Launching\launch.h"
#undef main

int main(int argc, char** argv)
{
	int windowWidth(0);
	int windowHeight(0);

	do {
		printf("Taille de la fenetre: ");
		scanf_s("%d %d", &windowWidth, &windowHeight);
	} while (windowWidth < 300 || windowWidth > 2000 || windowHeight < 300 || windowHeight > 1500);

	std::thread gameOfLife(launchWindow, windowWidth, windowHeight);


	std::string test = "bonjour salut";
	std::string tmp;
	int i = 0;
	while (test[i] != ' ')
	{
		tmp.append(test[i]);
	}
	std::cout << tmp << std::endl;

	gameOfLife.join();

	system("PAUSE");
	return 0;
}