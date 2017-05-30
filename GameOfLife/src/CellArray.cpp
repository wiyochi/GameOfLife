#include "CellArray.h"

CellArray::CellArray(int x, int y, int w, int h, int nW, int nH)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_cellNbW = nW;
	m_cellNbH = nH;
	m_spacing = 6;
	this->createCells();
}

CellArray::~CellArray()
{
	for (int i = 0; i < m_cellNbW; i++)
	{
		for (int j = 0; j < m_cellNbH; j++)
		{
			delete cellArray[i][j];
		}
	}
	for (int i = 0; i < m_cellNbW; i++)
	{
		delete cellArray[i];
	}
	delete cellArray;
}

void CellArray::createCells()
{
	int X = (m_width / m_cellNbW)-m_spacing;
	int Y = (m_height / m_cellNbH)-m_spacing;
	cellArray = new Cell**[m_cellNbW];
	for (int i = 0; i < m_cellNbW; i++)
	{
		cellArray[i] = new Cell*[m_cellNbH];
		for (int j = 0; j < m_cellNbH; j++)
		{
			cellArray[i][j] = new Cell(m_x + (X+m_spacing) * i, m_y + (Y+ m_spacing) * j, X, Y, false);
		}
	}
}

void CellArray::render(SDL_Renderer * renderer)
{
	int X = (m_width / m_cellNbW) - m_spacing;
	int Y = (m_height / m_cellNbH) - m_spacing;
	int xLine;
	int yLine;

	for (int i = 0; i < m_cellNbW; i++)
	{
		for (int j = 0; j < m_cellNbH; j++)
		{
			cellArray[i][j]->render(renderer);
		}
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = 0; i < m_cellNbW+1; i++)
	{
		xLine = m_x + (X + m_spacing) * i - m_spacing / 2;
		SDL_RenderDrawLine(renderer, xLine, m_y, xLine, m_y + (Y + m_spacing) * m_cellNbW - m_spacing);
	}
	for (int i = 0; i < m_cellNbW+1; i++)
	{
		yLine = m_y + (Y + m_spacing) * i - m_spacing / 2;
		SDL_RenderDrawLine(renderer, m_x, yLine, m_x + (X + m_spacing) * m_cellNbH - m_spacing, yLine);
	}
}

void CellArray::changeStates()
{
	int nbNeighboringCells;
	std::vector<std::vector<int>> index;
	index.resize(2);
	for (int i = 0; i < m_cellNbW; i++)
	{
		for (int j = 0; j < m_cellNbH; j++)
		{
			nbNeighboringCells = this->checkAliveAround(i, j);
			if (cellArray[i][j]->isAlive())
			{
				if (nbNeighboringCells < 2 || nbNeighboringCells>3) {
					index[0].push_back(i);
					index[1].push_back(j);
					//cellArray[i][j]->changeState();
				}
			}
			else
			{
				if (nbNeighboringCells == 3) {
					index[0].push_back(i);
					index[1].push_back(j);
					//cellArray[i][j]->changeState();
				}
			}
		}
	}
	for (int i = 0; i < index[0].size(); i++)
		cellArray[index[0][i]][index[1][i]]->changeState();
}

int CellArray::checkAliveAround(int i, int j)
{
	int count = 0;
	bool left = true;
	bool right = true;
	bool top = true;
	bool bottom = true;

	if (j <= 0)
		left = false;
	if (j >= m_cellNbH-1)
		right = false;
	if (i <= 0)
		top = false;
	if (i >= m_cellNbW-1)
		bottom = false;


	if (top && left && cellArray[i - 1][j - 1]->isAlive())
		count++;
	if (top && cellArray[i - 1][j]->isAlive())
		count++;
	if (top && right && cellArray[i - 1][j + 1]->isAlive())
		count++;
	/*if (i == 3 && j == 4)
		printf("left : %d et i,j-1 : %d\n", left, cellArray[i][j - 1]->isAlive());*/
	if (left && cellArray[i][j - 1]->isAlive())
		count++;
	if (right && cellArray[i][j + 1]->isAlive())
		count++;
	if (bottom && left && cellArray[i + 1][j - 1]->isAlive())
		count++;
	if (bottom && cellArray[i + 1][j]->isAlive())
		count++;
	if (bottom && right && cellArray[i + 1][j + 1]->isAlive())
		count++;

	return count;
}

void CellArray::createShip(int x, int y)
{
	if (x + 2 > m_cellNbW || y + 2 > m_cellNbH)
		printf("Impossible");
	else {
		cellArray[x][y]->changeState(true);
		cellArray[x+2][y]->changeState(true);
		cellArray[x+2][y+1]->changeState(true);
		cellArray[x+1][y+1]->changeState(true);
		cellArray[x+1][y+2]->changeState(true);
	}
}

void CellArray::randomize(int percent)
{
	std::srand(std::time(NULL));
	int random;
	for (int i = 0; i < m_cellNbW; i++)
	{
		for (int j = 0; j < m_cellNbH; j++)
		{
			random = rand()%100;
			if (random<percent)
				cellArray[i][j]->changeState(true);
		}
	}
}
