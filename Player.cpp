#include "Player.h"

Player::Player() :
	Entity::Entity{ 0, 0 }
{
	amount = 0;
}

void Player::teleport(Map* map)
{
	int sx = map->get_start_point().first;
	int sy = map->get_start_point().second;
	if (sx < 0 || sy < 0)
	{
		throw ExceptionWrongCoordinates{ sx, sy };
	}
	x = sx;
	y = sy;
}

void Player::walk(Map* map, directions direction) noexcept
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
		amount++;
		try
		{
			map->destroy_coin(x, y);
		}
		catch (ExceptionCoinDoesNotExists& e)
		{
			amount--;
		}
	}
}

void Player::display() noexcept
{
	move(y, x);
	attrset(COLOR_PAIR(color_player) | A_BOLD);
	printw("%c", tileplayer);
	attrset(color_default);
}

Player::~Player() noexcept
{
}

