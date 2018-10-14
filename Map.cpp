#include "Map.h"

Map::Map(const char* path)
{
	std::ifstream file;
	file.open(path, std::ifstream::binary | std::ifstream::in);
	if(file.fail())
	{
		file.close();
		throw(ExceptionBadFile{});
	}
	else
	{
		//kod
		//jak sie spierdoli tutaj to wywolaj destruktor
		file.close();
	}
}

void Map::add_area(Area* area)
{
	areas.push_back(area);
}

void Map::add_coin(unsigned int x, unsigned int y)
{
	if(!is_walkable(x, y))
	{
		throw(ExceptionInaccessibleCoin{ x, y });
	}
	for(unsigned int i = 0; i < coins.size(); i++)
	{
		if(coins[i].is_this_you(x, y))
		{
			throw(ExceptionDuplicateCoin{ x, y });
		}
	}
	coins.push_back({ x, y });
}

std::pair<unsigned int, unsigned int> Map::get_start_point()
{
	return start_point;
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

