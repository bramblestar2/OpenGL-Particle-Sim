#include "Cell.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <iostream>

Cell::Cell(int _ID)
{
	setID(_ID);
	setCellPosition(Vec2i());
	setColor(Vec4f(0,0,0,0));
}

int Cell::getID() const
{
	return id;
}

Vec4f Cell::getColor() const
{
	return color;
}

void Cell::setSize(Vec2f _Size)
{
	size = _Size;
}

void Cell::setCellPosition(Vec2i _Position)
{
	cellPosition = _Position;
}

Vec2i Cell::getCellPosition() const
{
	return cellPosition;
}

Vec2f Cell::getSize() const
{
	return size;
}

void Cell::render()
{
	float left = cellPosition.x * size.x;
	float right = left + size.x;
	float top = cellPosition.y * size.y;
	float bottom = top + size.y;

	glBegin(GL_QUADS);
	glColor4f(color.x, color.y, color.z, color.a);
	glNormal3d(0,0,1);
	glVertex2f(left, top);
	glNormal3d(0,0,1);
	glVertex2f(right, top);
	glNormal3d(0,0,1);
	glVertex2f(right, bottom);
	glNormal3d(0,0,1);
	glVertex2f(left, bottom);
	glEnd();
}

void Cell::update(Cell*** _Grid, Vec2i _Max_Size)
{
}

void Cell::setID(int _ID)
{
	id = _ID;
}

void Cell::setColor(Vec4f _Color)
{
	color = _Color;
}

void Cell::deallocateMem(Cell*** _Grid, int _X, int _Y)
{
	delete _Grid[_X][_Y];
}
