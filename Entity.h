#pragma once
#include <ncurses.h>
#include "Enumerations.h"
#include "Constants.h"
#include "Exceptions.h"

class Entity
{
protected:
	int x;
	int y;
	void set_coordinates(int x, int y);
public:
	Entity(int x, int y);
	bool is_this_you(int tx, int ty) noexcept;
	virtual void display() noexcept  = 0;
	virtual ~Entity() noexcept = 0;
};

