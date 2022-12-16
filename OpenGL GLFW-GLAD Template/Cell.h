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
	void setCellPosition(Vec2i _Position);

	Vec2i getCellPosition() const;
	Vec2f getSize() const;

	void render();

	/// <summary>
	/// Updates the grid with the new cells position
	/// </summary>
	/// <param name="_Max_Size">Width and Height of array</param>
	virtual void update(Cell*** _Grid, Vec2i _Max_Size) = 0;

protected:
	void setID(int _ID);
	void setColor(Vec3f _Color);

	void deallocateMem(Cell*** _Grid, int _X, int _Y);
private:
	Vec2f size;
	Vec2i cellPosition;
	Vec3f color;
	int id;
};

