#include "Cell.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <iostream>

Cell::Cell(int _ID)
{
	setID(_ID);
}

int Cell::getID() const
{
	return id;
}

Vec3f Cell::getColor() const
{
	return color;
}

void Cell::setSize(Vec2f _Size)
{
	size = _Size;
}

void Cell::setCellPosition(Vec2f _Position)
{
	cellPosition = _Position;
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
	glColor3f(color.x, color.y, color.z);
	glVertex2f(left, top);
	glVertex2f(right, top);
	glVertex2f(right, bottom);
	glVertex2f(left, bottom);
	glEnd();
}

void Cell::setID(int _ID)
{
	id = _ID;
}

void Cell::setColor(Vec3f _Color)
{
	color = _Color;
}
