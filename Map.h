#pragma once
#include "Area.h"
#include "Coin.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include "Exceptions.h"

class Map
{
private:
	std::pair<unsigned int, unsigned int> start_point;
	std::vector<Area*> areas;
	std::vector<Coin> coins;
	void add_area(Area* area);
	void add_coin(unsigned int x, unsigned int y);
public:
	Map(const char* path);
	std::pair<unsigned int, unsigned int> get_start_point();
	bool is_walkable(unsigned int tx, unsigned int ty);
	bool collect_coin(unsigned int tx, unsigned int ty);
	int remaining_coins();
	void display();
	~Map();
};

