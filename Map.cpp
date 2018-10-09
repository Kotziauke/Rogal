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
	bool exists = false;
	for(auto &coin : coins)
	{
		if(coin.x == x && coin.y == y)
		{
			exists = true;
			throw "A coin already exists at this place!\n";
			break;
		}
	}
	if(!exists)
	{
		coins.push_back({ x, y });
	}
}

int Map::remaining_coins()
{
	return coins.size();
}

void Map::move_player(Player& player, int sx, int sy)
{
	for(auto &area : areas)
	{
		if(player.x + sx >= area->x && player.x + sx < area->x + area->w && player.y + sy >= area->y && player.y + sy < area->y + area->h)
		{
			player.x += sx;
			player.y += sy;
			break;
		}
	}
	for(unsigned int i = 0; i < coins.size(); i++)
	{
		if(player.x == coins[i].x && player.y == coins[i].y)
		{
			player.amount++;
			coins.erase(coins.begin() + i);
			break;
		}
	}
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

