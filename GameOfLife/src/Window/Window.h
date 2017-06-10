#pragma once
#include "SDL.h"
#include <iostream>

class Window
{
public:
	Window(const char* title, int x, int y, int width, int height);
	~Window();
	bool isOpen();
	void close();
	void eventKey();
	void drawRectangle(int x, int y, int width, int height);
	void render();
	SDL_Renderer* getRenderer();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event m_event;
	bool m_open;
	const char* m_title;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};