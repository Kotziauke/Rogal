#pragma once
#include "Area.h"
#include "Coin.h"
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
	bool is_walkable(unsigned int tx, unsigned int ty);
	bool collect_coin(unsigned int tx, unsigned int ty);
	int remaining_coins();
	void display();
	~Map();
};

