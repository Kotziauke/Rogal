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

