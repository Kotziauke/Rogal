/*
	Maciej Gabryś
	gm41357, gr. 211a
	
	9.10.2018
*/

#include <ncurses.h>
#include <iostream>
#include <vector>
#include "Area.h"
#include "Coin.h"
#include "Map.h"
#include "Player.h"
#include "Exceptions.h"

void init();
void quit();

int main()
{
	init();
	Player player;
	std::vector<Map*> maps;
	try
	{
		maps.push_back(new Map{ "1.map" });
		maps.push_back(new Map{ "2.map" });
		maps.push_back(new Map{ "3.map" });
	}
	catch(Exception& e)
	{
		for(auto& map : maps)
		{
			delete map;
		}
		maps.clear();
		quit();
		std::cout << e.what();
		return -1;
	}
	
	unsigned int n = 1;
	for(auto& map : maps)
	{
		player.teleport(map);
		while(map->remaining_coins() > 0)
		{
			erase();
			map->display();
			move(0, 0);
			printw("Level %d, coins=%d, left=%d", n, player.get_amount(), map->remaining_coins());
			player.display();
			switch(getch())
			{
			case 'a':
				player.walk(map, -1, 0);
				break;
			case 's':
				player.walk(map, 0, 1);
				break;
			case 'w':
				player.walk(map, 0, -1);
				break;
			case 'd':
				player.walk(map, 1, 0);
				break;
			case 'q':
				for(auto& map : maps)
				{
					delete map;
				}
				maps.clear();
				quit();
				return 0;
			}
		}
		n++;
	}
	for(auto& map : maps)
	{
		delete map;
	}
	maps.clear();
	quit();
	return 0;
}

void init()
{
	initscr();
	raw();
	keypad(stdscr, true);
	noecho();
	start_color();
	use_default_colors();
	curs_set(0);
	init_pair(1, COLOR_BLUE, -1); //ściany
	init_pair(2, COLOR_WHITE, -1); //podłogi
	init_pair(3, COLOR_CYAN, -1); //ścieżki
	init_pair(4, COLOR_RED, -1); //gracz
	init_pair(5, COLOR_YELLOW, -1); //pieniądze
}

void quit()
{
	endwin();
}

