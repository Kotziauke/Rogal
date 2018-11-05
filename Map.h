#pragma once
#include "Area.h"
#include "Room.h"
#include "Hallway.h"
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
	std::pair<int, int> start_point;
	std::vector<Area*> areas;
	std::vector<Coin> coins;
	void add_area(Area* area);
	void destroy_areas();
	void add_coin(int x, int y);
public:
	Map(std::string path); //dopisac jakie rzuca wyjatki
	inline std::pair<unsigned int, unsigned int> get_start_point()
	{
		return start_point;
	}
	bool is_walkable(int tx, int ty);
	bool destroy_coin(int tx, int ty);
	inline int remaining_coins()
	{
		return coins.size();
	}
	void display();
	~Map();
};

