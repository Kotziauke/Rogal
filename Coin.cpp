#include "Coin.h"

Coin::Coin(unsigned int x, unsigned int y) :
	Entity::Entity{ x, y }
{
}

void Coin::display()
{
	move(y, x);
	attrset(COLOR_PAIR(5) | A_BOLD);
	printw("$");
	attrset(0);
}

Coin::~Coin()
{
}

