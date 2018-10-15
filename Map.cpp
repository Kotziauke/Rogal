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
		int x;
		int y;
		int w;
		int h;
		bool start_set = false;
		int ch;
		while((ch = file.get()) != -1)
		{
			switch(ch)
			{
			case 'R':
				x = file.get();
				y = file.get();
				w = file.get();
				h = file.get();
				if(x == -1 || y == -1 || w == -1 || h == -1)
				{
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
				try
				{
					add_area(new Room{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
				}
				catch(Exception& e)
				{
					destroy_areas();
					throw(e);
				}
				break;
			case 'H':
				x = file.get();
				y = file.get();
				w = file.get();
				h = file.get();
				if(x == -1 || y == -1 || w == -1 || h == -1)
				{
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
				try
				{
					add_area(new Hallway{ (unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h });
				}
				catch(Exception& e)
				{
					destroy_areas();
					throw(e);
				}
				break;
			case 'C':
				x = file.get();
				y = file.get();
				if(x == -1 || y == -1)
				{
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
				try
				{
					add_coin((unsigned int)x, (unsigned int)y);
				}
				catch(Exception& e)
				{
					destroy_areas();
					throw(e);
				}
				break;
			case 'S':
				x = file.get();
				y = file.get();
				if(x == -1 || y == -1)
				{
					destroy_areas();
					throw(ExceptionEndOfFile{});
				}
				try
				{
					start_point.first = (unsigned int)x;
					start_point.second = (unsigned int)y;
					start_set = true;
				}
				catch(Exception& e)
				{
					destroy_areas();
					throw(e);
				}
				break;
			default:
				destroy_areas();
				throw(ExceptionUnknownCharacter{});
				break;
			}
		}
		if(!start_set)
		{
			destroy_areas();
			throw(ExceptionNoStartPoint{});
		}
		if(!is_walkable(start_point.first, start_point.second))
		{
			destroy_areas();
			throw(ExceptionStartPointInVoid{});
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
	for(auto& area : areas)
	{
		delete area;
	}
	areas.clear();
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
	for(auto& area : areas)
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
	for(auto& area : areas)
	{
		area->display();
	}
	for(auto& coin : coins)
	{
		coin.display();
	}
}

Map::~Map()
{
	destroy_areas();
}

