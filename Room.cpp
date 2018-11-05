#include "Room.h"

Room::Room(int x, int y, int w, int h) :
	Area::Area{ x, y, w, h }
{
}

void Room::display() noexcept
{
	for (int j = y; j < y + h; j++)
	{
		for (int i = x; i < x + w; i++)
		{
			move(j, i);
			attrset(COLOR_PAIR(color_floor) | A_BOLD);
			printw("%c", tilefloor);
		}
		move(j, x - 1);
		attrset(COLOR_PAIR(color_wall) | A_BOLD);
		printw("%c", tilewall);
		move(j, x + w);
		printw("%c", tilewall);
	}
	for (int i = x - 1; i < x + w + 1; i++)
	{
		move(y - 1, i);
		attrset(COLOR_PAIR(color_wall) | A_BOLD);
		printw("%c", tilewall);
		move(y + h, i);
		printw("%c", tilewall);
	}
	attrset(color_default);
}

Room::~Room() noexcept
{
}

