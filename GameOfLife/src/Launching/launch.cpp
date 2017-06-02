#include "launch.h"

void launchWindow(Window* mainWindow, SDL_Renderer* renderer, CellArray* cellTab)
{
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