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
		int w = 0;
		int h = 0;
		bool start_set = false;
		int ch = -1;
		try
		{
			while ((ch = file.get()) != -1)
			{
				switch (ch)
				{
				case 'R':
				case 'H':
					w = file.get();
					h = file.get();
					if (w == -1 || h == -1)
					{
						throw(ExceptionEndOfFile{ path.c_str() });
					}
				case 'C':
				case 'S':
					x = file.get();
					y = file.get();
					if (x == -1 || y == -1)
					{
						throw(ExceptionEndOfFile{ path.c_str() });
					}
					break;
				default:
					throw(ExceptionUnknownCharacter{ path.c_str(), (char)ch });
					break;
				}
				switch (ch)
				{
				case 'R':
					add_area(new Room{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
					break;
				case 'H':
					add_area(new Hallway{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
					break;
				case 'C':
					add_coin(path, (unsigned int)x, (unsigned int)y);
					break;
				case 'S':
					if (start_set)
					{
						throw(ExceptionDuplicateStartPoint{ path.c_str() });
					}
					if (!is_walkable((unsigned int)x, (unsigned int)y))
					{
						throw(ExceptionStartPointInVoid{ path.c_str() });
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
		if (!start_set)
		{
			destroy_areas();
			throw(ExceptionNoStartPoint{ path.c_str() });
		}
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

void Map::add_coin(std::string path, unsigned int x, unsigned int y)
{
	if (!is_walkable(x, y))
	{
		throw(ExceptionInaccessibleCoin{ path.c_str(), x, y });
	}
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i].is_this_you(x, y))
		{
			throw(ExceptionDuplicateCoin{ path.c_str(), x, y });
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
	for (auto& area : areas)
	{
		if (area->is_walkable(tx, ty))
		{
			return true;
		}
	}
	return false;
}

bool Map::collect_coin(unsigned int tx, unsigned int ty)
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

int Map::remaining_coins()
{
	return coins.size();
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

