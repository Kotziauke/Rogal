#pragma once
#include "Area.h"
#include "Coin.h"
#include "Player.h"
#include <vector>

class Map
{
private:
	std::vector<Area*> areas;
	std::vector<Coin> coins;
public:
	Map();
	void add_area(Area* area);
	void add_coin(unsigned int x, unsigned int y);
	int remaining_coins();
	void move_player(Player& player, int sx, int sy);
	void display();
	~Map();
};

