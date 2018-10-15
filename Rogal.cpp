/*
	Maciej Gabryś
	gm41357, gr. 211a
	
	15.10.2018
*/

#include <ncurses.h>
#include <iostream>
#include <string>
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
	Map* map = nullptr;
	std::string path;
	unsigned int n = 1;
	while(true)
	{
		path = std::to_string(n);
		path += ".map";
		try
		{
			map = new Map{ path.c_str() };
		}
		catch(ExceptionBadFile& e)
		{
			quit();
			std::cout << "No more levels!" << std::endl;
			return 0;
		}
		catch(Exception& e)
		{
			quit();
			std::cout << "Error while processing level \"" << path.c_str() << "\":" << std::endl << ">" << e.what();
			return -1;
		}
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
				delete map;
				quit();
				return 0;
			}
		}
		delete map;
		n++;
	}
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

