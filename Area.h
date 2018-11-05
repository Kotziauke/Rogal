#pragma once
#include <ncurses.h>
#include "Enumerations.h"
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
	bool is_walkable(int tx, int ty) noexcept;
	virtual void display() noexcept = 0;
	virtual ~Area() noexcept = 0;
};

