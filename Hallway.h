#pragma once
#include "Area.h"

class Hallway :
	public Area
{
public:
	Hallway(int x, int y, int w, int h);
	void display() override;
	~Hallway() override;
};

