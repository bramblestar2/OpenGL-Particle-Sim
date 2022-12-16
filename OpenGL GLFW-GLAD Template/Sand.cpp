#include "Sand.h"
#include <random>

Sand::Sand(Vec2f _Size, Vec2i _Position) : Cell((int)CellType::SAND)
{
	Cell::setColor(Vec3f(1.00, 0.87, 0.20));
	Cell::setSize(_Size);
	Cell::setCellPosition(_Position);
}

Sand::~Sand()
{
}

void Sand::update(Cell*** _Grid, Vec2i _Max_Size)
{
	Vec2i cellPos = Cell::getCellPosition();

	bool down = false;
	bool downLeft = false, downRight = false;
	//Checks
	//Down
	if (cellPos.y < _Max_Size.y - 1)
		if (_Grid[cellPos.x][cellPos.y + 1]->getID() == (int)CellType::AIR)
			down = true;
	//Down Left
	if (cellPos.x > 0 && cellPos.y < _Max_Size.y - 1)
		if (_Grid[cellPos.x-1][cellPos.y + 1]->getID() == (int)CellType::AIR)
			downLeft = true;
	//Down Right
	if (cellPos.x < _Max_Size.x - 1 && cellPos.y < _Max_Size.y - 1)
		if (_Grid[cellPos.x + 1][cellPos.y + 1]->getID() == (int)CellType::AIR)
			downRight = true;

	
	//Move cells position

	if (down)
		_Grid[cellPos.x][cellPos.y + 1] = 
		new Sand(Cell::getSize(), Vec2i(cellPos.x, cellPos.y + 1));
	else if (downLeft && downRight)
	{
		switch (rand() % 2)
		{
			//Down Left
		case 0:
			_Grid[cellPos.x - 1][cellPos.y + 1] = 
				new Sand(Cell::getSize(), Vec2i(cellPos.x - 1, cellPos.y + 1));
			break;
			//Down Right
		case 1:
			_Grid[cellPos.x + 1][cellPos.y + 1] = 
				new Sand(Cell::getSize(), Vec2i(cellPos.x + 1, cellPos.y + 1));
			break;
		}
	}
	else if (downLeft)
	{
			_Grid[cellPos.x - 1][cellPos.y + 1] = 
				new Sand(Cell::getSize(), Vec2i(cellPos.x - 1, cellPos.y + 1));
	}
	else if (downRight);
	{
			_Grid[cellPos.x + 1][cellPos.y + 1] = 
				new Sand(Cell::getSize(), Vec2i(cellPos.x + 1, cellPos.y + 1));
	}

	//Delete cell
	Cell::deallocateMem(_Grid, cellPos.x, cellPos.y);
}
