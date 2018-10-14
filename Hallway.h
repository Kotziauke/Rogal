#pragma once
#include "Area.h"

class Hallway :
	public Area
{
public:
	Hallway(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void display() override;
	~Hallway() override;
};

