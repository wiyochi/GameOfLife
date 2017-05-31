#include "GameOfLife.h"

GameOfLife::GameOfLife(int w, int h)
{
	m_width = w;
	m_height = h;
	m_window = new Window("Game of life", 100, 100, m_width + 2, m_height + 2);
	m_renderer = m_window->getRenderer();
	m_cellTab = new CellArray(4, 4, m_width, m_height, 30, 30);
	m_cellTab->randomize(20);
	std::thread eventThread(wait, this);
}

GameOfLife::~GameOfLife()
{
	delete m_cellTab;
	delete m_window;
}

void GameOfLife::loop()
{
	while (m_window->isOpen())
	{
		m_cellTab->render(m_renderer);
		m_window->render();
		m_cellTab->changeStates();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void GameOfLife::waitEvent()
{
	while (m_window->isOpen())
	{
		m_window->eventKey();
	}
}

void wait(GameOfLife* game)
{
	printf("Im in a thread\n");
	game->waitEvent();
}
