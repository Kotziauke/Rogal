#pragma once
#include <ncurses.h>

class Entity
{
protected:
	unsigned int x;
	unsigned int y;
public:
	Entity(unsigned int x, unsigned int y);
	bool is_this_you(unsigned int tx, unsigned int ty);
	virtual void display() = 0;
	virtual ~Entity() = 0;
};

