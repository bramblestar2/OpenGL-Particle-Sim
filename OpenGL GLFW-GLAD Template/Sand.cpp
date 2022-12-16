#include "Sand.h"

Sand::Sand(Vec2f _Size) : Cell((int)CellType::SAND)
{
	Cell::setColor(Vec3f(1.00, 0.87, 0.20));
	Cell::setSize(_Size);
}

Sand::~Sand()
{
}

void Sand::update()
{
}
