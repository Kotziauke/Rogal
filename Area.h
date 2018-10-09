#pragma once
#include <ncurses.h>

class Area
{
protected:
	//zrobic gettery
	const unsigned int x;
	const unsigned int y;
	const unsigned int w;
	const unsigned int h;
public:
	Area(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	bool is_walkable(unsigned int tx, unsigned int ty);
	virtual void display() = 0;
	virtual ~Area() = 0;
};

