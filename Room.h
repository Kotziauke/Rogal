#pragma once
#include "Area.h"

class Room :
	public Area
{
public:
	Room(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void display() override;
	~Room() override;
};

