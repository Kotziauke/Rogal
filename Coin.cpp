#include "Coin.h"

Coin::Coin(unsigned int x, unsigned int y) :
	Entity::Entity{ x, y }
{
}

void Coin::display()
{
	move(y, x);
	attrset(COLOR_PAIR(color_coin) | A_BOLD);
	printw("$");
	attrset(color_default);
}

Coin::~Coin()
{
}

