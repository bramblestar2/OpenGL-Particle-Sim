#pragma once
#include "Cell.h"

class Sand : public Cell
{
public:
	Sand(Vec2f _Size = Vec2f(1,1));
	~Sand();

	void update() override;
private:
};

