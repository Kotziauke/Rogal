#include "Map.h"

Map::Map(std::string path)
{
	std::ifstream file;
	file.open(path.c_str(), std::ifstream::binary | std::ifstream::in);
	if (file.fail())
	{
		file.close();
		throw ExceptionBadFile{};
	}
	else
	{
		char header[5];
		file.get(header, 5);
		if (strcmp(header, "MAP\x01") != 0)
		{
			file.close();
			throw ExceptionBadHeader{};
		}
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
					x = file.get();
					y = file.get();
					w = file.get();
					h = file.get();
					add_area(new Room{ x, y, w, h });
					break;
				case 'H':
					x = file.get();
					y = file.get();
					w = file.get();
					h = file.get();
					add_area(new Hallway{ x, y, w, h });
					break;
				case 'C':
					x = file.get();
					y = file.get();
					add_coin(x, y);
					break;
				case 'S':
					x = file.get();
					y = file.get();
					if (x < 0 || y < 0)
					{
						throw ExceptionWrongCoordinates{ x, y };
					}
					if (start_set == true)
					{
						throw ExceptionDuplicateStartPoint{};
					}
					if (is_walkable(x, y) == false)
					{
						throw ExceptionStartPointInVoid{};
					}
					start_point.first = x;
					start_point.second = y;
					start_set = true;
					break;
				default:
					throw ExceptionUnknownIdentifier{};
					break;
				}
			}
			if (start_set == false)
			{
				throw ExceptionNoStartPoint{};
			}
			if (remaining_coins() == 0)
			{
				throw ExceptionNoCoins{};
			}
		}
		catch (Exception& e)
		{
			destroy_areas();
			file.close();
			throw e;
		}
		file.close();
	}
}

void Map::add_area(Area* area) noexcept
{
	areas.push_back(area);
}

void Map::destroy_areas() noexcept
{
	for (auto& area : areas)
	{
		delete area;
	}
	areas.clear();
}

void Map::add_coin(int x, int y)
{
	if (is_walkable(x, y) == false)
	{
		throw ExceptionInaccessibleCoin{ x, y };
	}
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i].is_this_you(x, y))
		{
			throw ExceptionDuplicateCoin{ x, y };
		}
	}
	coins.push_back({ x, y });
}

void Map::destroy_coin(int tx, int ty)
{
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i].is_this_you(tx, ty))
		{
			coins.erase(coins.begin() + i);
			return;
		}
	}
	throw ExceptionCoinDoesNotExists{ tx, ty };
}

bool Map::is_walkable(int tx, int ty) noexcept
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

void Map::display() noexcept
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

Map::~Map() noexcept
{
	destroy_areas();
}

