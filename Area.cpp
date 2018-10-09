#include "Area.h"

Area::Area(unsigned int x, unsigned int y, unsigned int w, unsigned int h) :
	x { x },
	y { y },
	w { w },
	h { h }
{
}

bool Area::is_walkable(unsigned int tx, unsigned int ty)
{
	if(tx >= x && tx < x + w && ty >= y && ty < y + h)
	{
		return true;
	}
	return false;
}

Area::~Area()
{
}

