#pragma once
#include <ncurses.h>

class Entity
{
	friend class Map;
protected:
	unsigned int x;
	unsigned int y;
public:
	Entity(unsigned int x, unsigned int y);
	virtual void display() = 0;
	virtual ~Entity() = 0;
};

