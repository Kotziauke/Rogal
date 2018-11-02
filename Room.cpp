#include "Room.h"

Room::Room(unsigned int x, unsigned int y, unsigned int w, unsigned int h) :
	Area::Area{ x, y, w, h }
{
}

void Room::display()
{
	for (unsigned int j = y; j < y + h; j++)
	{
		for (unsigned int i = x; i < x + w; i++)
		{
			move(j, i);
			attrset(COLOR_PAIR(color_floor) | A_BOLD);
			printw(".");
		}
		move(j, x - 1);
		attrset(COLOR_PAIR(color_wall) | A_BOLD);
		printw("#");
		move(j, x + w);
		printw("#");
	}
	for (unsigned int i = x - 1; i < x + w + 1; i++)
	{
		move(y - 1, i);
		attrset(COLOR_PAIR(color_wall) | A_BOLD);
		printw("#");
		move(y + h, i);
		printw("#");
	}
	attrset(color_default);
}

Room::~Room()
{
}

