#pragma once
#include "Area.h"

class Corridor :
	public Area
{
public:
	Corridor(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void display() override;
	~Corridor() override;
};

