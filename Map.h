#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <string.h>
#include "Area.h"
#include "Room.h"
#include "Hallway.h"
#include "Coin.h"
#include "Exceptions.h"

class Map
{
private:
	std::pair<int, int> start_point;
	std::vector<Area*> areas;
	std::vector<Coin> coins;
	void add_area(Area* area) noexcept;
	void destroy_areas() noexcept;
	void add_coin(int x, int y);
public:
	Map(std::string path);
	inline std::pair<unsigned int, unsigned int> get_start_point() noexcept
	{
		return start_point;
	}
	void destroy_coin(int tx, int ty);
	bool is_walkable(int tx, int ty) noexcept;
	inline int remaining_coins() noexcept
	{
		return coins.size();
	}
	void display() noexcept;
	~Map() noexcept;
};

