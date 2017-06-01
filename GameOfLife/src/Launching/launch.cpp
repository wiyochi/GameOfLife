#include "launch.h"

void launchWindow(int width, int height)
{
	Window* mainWindow = new Window("Game of life", 100, 100, width + 2, height + 2);
	SDL_Renderer* renderer = mainWindow->getRenderer();
	CellArray* cellTab = new CellArray(4, 4, width, height, 30, 30);
	cellTab->createShip(2, 2);
	cellTab->randomize(20);

	std::thread eventThread(waitEvent, mainWindow, renderer, cellTab);

	while (mainWindow->isOpen())
	{
		mainWindow->eventKey();
	}

	eventThread.join();
	delete cellTab;
	delete mainWindow;
}

void waitEvent(Window* window, SDL_Renderer* renderer, CellArray* cellTab)
{
	while (window->isOpen())
	{
		cellTab->render(renderer);
		window->render();
		cellTab->changeStates();
	}
}