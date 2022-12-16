#pragma once
#include "Essentials/Vec3/Vec3.h"
#include "Essentials/Vec2/Vec2.h"

enum class CellType
{
	AIR = 0,
	SAND,
	WATER,
	STONE,
};

class Cell
{
public:
	Cell(int _ID);

	int getID() const;
	Vec3f getColor() const;

	void setSize(Vec2f _Size);
	void setCellPosition(Vec2f _Position);

	Vec2f getSize() const;

	void render();
	virtual void update() = 0;

protected:
	void setID(int _ID);
	void setColor(Vec3f _Color);
private:
	Vec2f size;
	Vec2f cellPosition;
	Vec3f color;
	int id;
};

