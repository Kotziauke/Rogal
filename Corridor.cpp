#include "Corridor.h"

Corridor::Corridor(unsigned int x, unsigned int y, unsigned int w, unsigned int h) :
	Area::Area{ x, y, w, h }
{
}

void Corridor::display()
{
	for(unsigned int j = y; j < y + h; j++)
	{
		for(unsigned int i = x; i < x + w; i++)
		{
			move(j, i);
			attrset(COLOR_PAIR(3) | A_BOLD);
			printw("+");
		}
	}
	attrset(0);
}

Corridor::~Corridor()
{
}

