#include "Cell.h"

Cell::Cell(int x, int y, int w, int h, int alive)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_alive = alive;
	m_cellRect = { m_x, m_y, m_width, m_height };
}

void Cell::changeState()
{
	m_alive = !(m_alive);
}

void Cell::changeState(bool life)
{
	if ((life && !m_alive) || (!life && m_alive))
		m_alive = !(m_alive);
}

bool Cell::isAlive()
{
	return m_alive;
}

void Cell::render(SDL_Renderer* renderer)
{
	if (m_alive)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
	SDL_RenderFillRect(renderer, &m_cellRect);
}
