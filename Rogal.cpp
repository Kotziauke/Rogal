/*
	Maciej Gabryś
	gm41357, gr. 211a
	
	9.10.2018
*/

#include <ncurses.h>
#include <iostream>
#include "Area.h"
#include "Room.h"
#include "Corridor.h"
#include "Coin.h"
#include "Map.h"
#include "Player.h"

void init();
void quit();
void map_error(const char* msg);

int main()
{
	init();
	Map lvl[3];
	Map* map = nullptr;
	Player player;
	
	//poziom 1
	lvl[0].add_area(new Room{ 2, 3, 5, 3 });
	try
	{
		lvl[0].add_coin(5, 4);
		//lvl[0].add_coin(5, 4); //duplikat!
	}
	catch(const char* msg)
	{
		map_error(msg);
	}
	
	//poziom 2
	lvl[1].add_area(new Room{ 2, 3, 7, 4 });
	lvl[1].add_area(new Room{ 6, 12, 10, 3 });
	lvl[1].add_area(new Corridor{ 7, 7, 1, 5 });
	try
	{
		lvl[1].add_coin(6, 5);
		lvl[1].add_coin(14, 13);
	}
	catch(const char* msg)
	{
		map_error(msg);
	}
	
	//poziom 3
	lvl[2].add_area(new Room{ 2, 3, 3, 3 });
	lvl[2].add_area(new Room{ 8, 3, 3, 3 });
	lvl[2].add_area(new Room{ 14, 3, 3, 3 });
	lvl[2].add_area(new Room{ 2, 9, 3, 3 });
	lvl[2].add_area(new Room{ 8, 9, 3, 3 });
	lvl[2].add_area(new Room{ 14, 9, 3, 3 });
	lvl[2].add_area(new Room{ 2, 15, 3, 3 });
	lvl[2].add_area(new Room{ 8, 15, 3, 3 });
	lvl[2].add_area(new Room{ 14, 15, 3, 3 });
	lvl[2].add_area(new Corridor{ 3, 6, 1, 3 });
	lvl[2].add_area(new Corridor{ 15, 6, 1, 3 });
	lvl[2].add_area(new Corridor{ 9, 12, 1, 3 });
	lvl[2].add_area(new Corridor{ 11, 4, 3, 1 });
	lvl[2].add_area(new Corridor{ 5, 10, 3, 1 });
	lvl[2].add_area(new Corridor{ 11, 10, 3, 1 });
	lvl[2].add_area(new Corridor{ 5, 16, 3, 1 });
	lvl[2].add_area(new Corridor{ 11, 16, 3, 1 });
	try
	{
		lvl[2].add_coin(3, 10);
		lvl[2].add_coin(9, 4);
		lvl[2].add_coin(15, 16);
	}
	catch(const char* msg)
	{
		map_error(msg);
	}
	
	for(int n = 0; n < 3; n++)
	{
		map = &lvl[n];
		player.respawn();
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
				map->move_player(player, -1, 0);
				break;
			case 's':
				map->move_player(player, 0, 1);
				break;
			case 'w':
				map->move_player(player, 0, -1);
				break;
			case 'd':
				map->move_player(player, 1, 0);
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

void map_error(const char* msg)
{
	attrset(COLOR_PAIR(4) | A_BOLD);
	printw("%s", msg);
	attrset(0);
	getch();
}

