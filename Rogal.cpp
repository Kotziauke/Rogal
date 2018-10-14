/*
	Maciej Gabryś
	gm41357, gr. 211a
	
	9.10.2018
*/

#include <ncurses.h>
#include <iostream>
#include "Area.h"
#include "Coin.h"
#include "Map.h"
#include "Player.h"
#include "Exceptions.h"

void init();
void quit();

int main()
{
	Map* map = nullptr;
	
	try
	{
		Map lv1{ "a.txt" };
		map = &lv1;
	}
	catch(Exception& e)
	{
		std::cout << "Error while loading a map from xxx file:" << std::endl;
		std::cout << e.what();
		return -1;
	}
	catch(...)
	{
		std::cout << "???" << std::endl;
		return -2;
	}
	
	std::cout << "Poprawnie." << std::endl;
	return 0;
	
	init();
	Player player;
	
	for(int n = 0; n < 1; n++)
	{
		player.teleport(map);
		bool loop = true;
		while(loop)
		{
			erase();
			map->display();
			move(0, 0);
			printw("Level %d, coins=%d, left=%d", n + 1, player.get_amount(), map->remaining_coins());
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
				loop = false;
				break;
			}
			if(map->remaining_coins() == 0)
			{
				loop = false;
			}
		}
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

