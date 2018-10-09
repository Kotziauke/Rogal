#include "Map.h"

Map::Map()
{
}

void Map::add_area(Area* area)
{
	areas.push_back(area);
}

void Map::add_coin(unsigned int x, unsigned int y)
{
	coins.push_back({ x, y });
}

bool Map::is_walkable(unsigned int tx, unsigned int ty)
{
	for(auto &area : areas)
	{
		if(area->is_walkable(tx, ty))
		{
			return true;
		}
	}
	return false;
}

bool Map::collect_coin(unsigned int tx, unsigned int ty)
{
	for(unsigned int i = 0; i < coins.size(); i++)
	{
		if(coins[i].is_this_you(tx, ty))
		{
			coins.erase(coins.begin() + i);
			return true;
		}
	}
	return false;
}

int Map::remaining_coins()
{
	return coins.size();
}

void Map::display()
{
	for(auto &area : areas)
	{
		area->display();
	}
	for(auto &coin : coins)
	{
		coin.display();
	}
}

Map::~Map()
{
	for(auto &area : areas)
	{
		delete area;
	}
}

