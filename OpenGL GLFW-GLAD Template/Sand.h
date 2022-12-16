#pragma once
#include "Cell.h"

class Sand : public Cell
{
public:
	Sand(Vec2f _Size = Vec2f(1,1), Vec2i _Position = Vec2i());
	~Sand();

	/// <summary>
	/// Updates the grid with the new cells position
	/// </summary>
	/// <param name="_Max_Size">Width and Height of array</param>
	void update(Cell*** _Grid, Vec2i _Max_Size) override;
private:
};

