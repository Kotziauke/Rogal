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
		throw(ExceptionBadFile{});
	}
	else
	{
		int x = 0;
		int y = 0;
		int w = 0;
		int h = 0;
		bool start_set = false;
		int ch = -1;
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
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
			case 'C':
			case 'S':
				x = file.get();
				y = file.get();
				if (x == -1 || y == -1)
				{
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
				break;
			default:
				destroy_areas();
				throw(ExceptionUnknownCharacter{});
				break;
			}
			try
			{
				switch (ch)
				{
				case 'R':
					add_area(new Room{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
					break;
				case 'H':
					add_area(new Hallway{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
					break;
				case 'C':
					add_coin((unsigned int)x, (unsigned int)y);
					break;
				case 'S':
					if (!is_walkable((unsigned int)x, (unsigned int)y))
					{
						throw(ExceptionStartPointInVoid{});
					}
					if (start_set)
					{
						destroy_areas();
						throw(ExceptionDuplicateStartPoint{});
					}
					start_point.first = (unsigned int)x;
					start_point.second = (unsigned int)y;
					start_set = true;
					break;
				}
			}
			catch (Exception& e)
			{
				destroy_areas();
				throw(e);
			}
		}
		if (!start_set)
		{
			destroy_areas();
			throw(ExceptionNoStartPoint{});
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

void Map::add_coin(unsigned int x, unsigned int y)
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

