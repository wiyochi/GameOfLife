#pragma once
#include "SDL.h"

class Cell
{
public:
	Cell(int x, int y, int w, int h, int alive);
	void changeState();
	void changeState(bool life);
	bool isAlive();
	void render(SDL_Renderer* renderer);

private:
	SDL_Rect m_cellRect;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	bool m_alive;
};