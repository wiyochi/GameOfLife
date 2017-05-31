#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "SDL.h"
#include "Window/Window.h"
#include "Cell/Cell.h"
#include "Cell/CellArray.h"
#include "GameOfLife.h"
#undef main

//void waitEvent(Window *mainWindow, CellArray *cellTab, SDL_Renderer *renderer);
void waitEvent(GameOfLife *game);

int main(int argc, char** argv)
{
	int windowWidth(0);
	int windowHeight(0);

	do {
		printf("Taille de la fenetre: ");
		scanf_s("%d %d", &windowWidth, &windowHeight);
	} while (windowWidth < 300 || windowWidth > 2000 || windowHeight < 300 || windowHeight > 1500);

	GameOfLife* game = new GameOfLife(windowWidth, windowHeight);
	game->loop();
	//Window* mainWindow = new Window("Game of life", 100, 100, windowWidth+2, windowHeight+2);
	//SDL_Renderer* renderer = mainWindow->getRenderer();
	//CellArray* cellTab = new CellArray(4, 4, windowHeight, windowHeight, 30, 30);
	//cellTab->createShip(2, 2);
	//cellTab->randomize(20);

	//std::thread eventThread(waitEvent, mainWindow, cellTab, renderer);
	
	//while (mainWindow->isOpen())
	//{
	//	cellTab->render(renderer);
	//	mainWindow->render();
	//	mainWindow->eventKey();
	//	cellTab->changeStates();
	//	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	//}

	//eventThread.join();
	//delete cellTab;
	//delete mainWindow;
	
	delete game;

	system("PAUSE");
	return 0;
}

void waitEvent(GameOfLife *game)
{
	game->waitEvent();
}