#include "Player.h"

Player::Player() :
	Entity::Entity{ 0, 0 },
	amount { 0 }
{
}

void Player::teleport(Map* map)
{
	x = map->get_start_point().first;
	y = map->get_start_point().second;
}

void Player::walk(Map* map, int sx, int sy)
{
	if(map->is_walkable(x + sx, y + sy))
	{
		x += sx;
		y += sy;
		if(map->collect_coin(x, y))
		{
			amount++;
		}
	}
}

unsigned int Player::get_amount()
{
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

