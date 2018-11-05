#include "Area.h"

Area::Area(int x, int y, int w, int h)
{
	set_dimensions(x, y, w, h);
}

void Area::set_dimensions(int x, int y, int w, int h)
{
	if (x < 0 || y < 0)
	{
		throw ExceptionWrongCoordinates{ x, y };
	}
	if (w <= 0 || h <= 0)
	{
		throw ExceptionWrongDimensions{ w, h };
	}
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Area::is_walkable(int tx, int ty)
{
	if (tx >= x && tx < x + w && ty >= y && ty < y + h)
	{
		return true;
	}
	return false;
}

Area::~Area()
{
}

