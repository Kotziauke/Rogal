#include "Map.h"
/*
 * Opis metody
 */
Map::Map(std::string path)
{
	std::ifstream file;
	file.open(path.c_str(), std::ifstream::binary | std::ifstream::in);
	if (file.fail())
	{
		file.close();
		throw(ExceptionBadFile{ path.c_str() });
	}
	else
	{
		int x = 0;
		int y = 0;
		bool start_set = false;
		int ch = -1;
		try
		{
			while ((ch = file.get()) != -1)
			{
				switch (ch)
				{
				case 'R':
					add_area(new Room{ file.get(), file.get(), file.get(), file.get() });
					break;
				case 'H':
					add_area(new Hallway{ file.get(), file.get(), file.get(), file.get() });
					break;
				case 'C':
					add_coin(file.get(), file.get());
					break;
				case 'S':
					x = file.get();
					y = file.get();
					if (x < 0 || y < 0)
					{
						throw(ExceptionWrongCoordinates{ x, y });
					}
					if (start_set == true)
					{
						throw(ExceptionDuplicateStartPoint{});
					}
					start_point.first = (unsigned int)x;
					start_point.second = (unsigned int)y;
					start_set = true;
					break;
				}
			}
		}
		catch (Exception& e)
		{
			destroy_areas();
			file.close();
			throw(e);
		}
		file.close();
	}
}

void Map::add_area(Area* area)
{
	areas.push_back(area);
}

void Map::destroy_areas()
{
	for (auto& area : areas)
	{
		delete area;
	}
	areas.clear();
}

void Map::add_coin(int x, int y)
{
	if (!is_walkable(x, y))
	{
		throw(ExceptionInaccessibleCoin{ x, y });
	}
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i].is_this_you(x, y))
		{
			throw(ExceptionDuplicateCoin{ x, y });
		}
	}
	coins.push_back({ x, y });
}

bool Map::is_walkable(int tx, int ty)
{
	for (auto& area : areas)
	{
		if (area->is_walkable(tx, ty))
		{
			return true;
		}
	}
	return false;
}

bool Map::destroy_coin(int tx, int ty)
{
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i].is_this_you(tx, ty))
		{
			coins.erase(coins.begin() + i);
			return true;
		}
	}
	return false;
}

void Map::display()
{
	for (auto& area : areas)
	{
		area->display();
	}
	for (auto& coin : coins)
	{
		coin.display();
	}
}

Map::~Map()
{
	destroy_areas();
}

