#pragma once
#include "Window\Window.h"
#include "SDL.h"
#include "Cell\CellArray.h"
#include <thread>
#include <chrono>

void wait(GameOfLife* game);

class GameOfLife
{
public:
	GameOfLife(int w, int h);
	~GameOfLife();
	void loop();
	void waitEvent();
private:
	int m_width;
	int m_height;
	Window* m_window;
	SDL_Renderer* m_renderer;
	CellArray* m_cellTab;
};