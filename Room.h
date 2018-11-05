#pragma once
#include "Area.h"

class Room :
	public Area
{
public:
	Room(int x, int y, int w, int h);
	void display() override;
	~Room() override;
};

