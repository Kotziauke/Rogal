#include "Player.h"

Player::Player() :
	Entity::Entity{ 3, 4 },
	amount { 0 }
{
}

void Player::respawn()
{
	x = 3;
	y = 4;
}

void Player::walk(Map& map, int sx, int sy)
{
	if(map.is_walkable(x + sx, y + sy))
	{
		x += sx;
		y += sy;
		if(map.collect_coin(x, y))
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

