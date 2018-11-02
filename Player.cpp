#include "Player.h"

Player::Player() :
	Entity::Entity{ 0, 0 },
	amount{ 0 }
{
}

void Player::teleport(Map* map)
{
	//rzucac wyjatek
	//pragma line/debug
	x = map->get_start_point().first;
	y = map->get_start_point().second;
}

void Player::walk(Map* map, directions direction)
{
	int sx = 0;
	int sy = 0;
	switch (direction)
	{
	case direction_left:
		sx = -1;
		break;
	case direction_right:
		sx = 1;
		break;
	case direction_up:
		sy = -1;
		break;
	case direction_down:
		sy = 1;
		break;
	}
	if (map->is_walkable(x + sx, y + sy) == true)
	{
		x += sx;
		y += sy;
		if (map->collect_coin(x, y) == true)
		{
			amount++;
		}
	}
}

unsigned int Player::get_amount()
{
	//jako inline
	return amount;
}

void Player::display()
{
	move(y, x);
	attrset(COLOR_PAIR(4) | A_BOLD);
	printw("@");
	attrset(0);
}

Player::~Player()
{
}

