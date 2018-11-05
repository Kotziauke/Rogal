#include "Hallway.h"

Hallway::Hallway(int x, int y, int w, int h) :
	Area::Area{ x, y, w, h }
{
}

void Hallway::display() noexcept
{
	for (int j = y; j < y + h; j++)
	{
		for (int i = x; i < x + w; i++)
		{
			move(j, i);
			attrset(COLOR_PAIR(color_hallway) | A_BOLD);
			printw("%c", tilehallway);
		}
	}
	attrset(color_default);
}

Hallway::~Hallway() noexcept
{
}

