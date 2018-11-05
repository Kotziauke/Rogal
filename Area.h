#pragma once
#include <ncurses.h>
#include "Constants.h"
#include "Exceptions.h"

class Area
{
protected:
	int x;
	int y;
	int w;
	int h;
	void set_dimensions(int x, int y, int w, int h);
public:
	Area(int x, int y, int w, int h);
	bool is_walkable(int tx, int ty);
	virtual void display() = 0;
	virtual ~Area() = 0;
};

