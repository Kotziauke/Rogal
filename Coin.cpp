#include "Coin.h"

Coin::Coin(int x, int y) :
	Entity::Entity{ x, y }
{
}

void Coin::display()
{
	move(y, x);
	attrset(COLOR_PAIR(color_coin) | A_BOLD);
	printw("%c", tilecoin);
	attrset(color_default);
}

Coin::~Coin()
{
}

