#include "Window.h"

Window::Window(const char* title, int x, int y, int width, int height)
{
	m_title = title;
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_open = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Failed SDL's initialization (%s)\n", SDL_GetError());
	}

	m_window = NULL;
	m_window = SDL_CreateWindow(m_title, m_x, m_y, m_width, m_height, SDL_WINDOW_RESIZABLE);
	
	m_renderer = NULL;
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Window::~Window()
{
	m_open = false;
	printf("Closing the window\n");
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Window::isOpen()
{
	return m_open;
}

void Window::eventKey()
{
	//SDL_WaitEvent(&m_event);
	SDL_PollEvent(&m_event);
	switch (m_event.type)
	{
	case SDL_KEYDOWN:
		std::cout << "La touche " << SDL_GetKeyName(m_event.key.keysym.sym) << " a été pressee!" << std::endl;
		break;
	case SDL_QUIT:
		m_open = false;
	}
}

void Window::drawRectangle(int x, int y, int width, int height)
{
	SDL_Rect rectangle;
	rectangle = { x, y, width, height };
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(m_renderer, &rectangle);
	SDL_RenderPresent(m_renderer);
}

void Window::render()
{
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

SDL_Renderer * Window::getRenderer()
{
	return m_renderer;
}
