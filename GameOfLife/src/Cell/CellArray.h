#pragma once
#include "Cell.h"
#include "SDL.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

class CellArray
{
public:
	CellArray(int x, int y, int w, int h, int nW, int nH);
	~CellArray();
	void createCells();
	void render(SDL_Renderer* renderer);
	void changeStates();
	int checkAliveAround(int i, int j);
	void createShip(int x, int y);
	void randomize(int percent);
	void clear();
	void changeSpeed(int speed);
	void play();
	void stop();

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_cellNbW;
	int m_cellNbH;
	int m_spacing;
	int m_speed;
	bool m_running;
	Cell*** cellArray;
};