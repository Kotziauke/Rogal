#pragma once
#include "Constants.h"
#include "Exceptions.h"
#include <ncurses.h>

class Entity
{
protected:
	int x;
	int y;
	void set_coordinates(int x, int y);
public:
	Entity(int x, int y);
	bool is_this_you(int tx, int ty);
	virtual void display() = 0;
	virtual ~Entity() = 0;
};

