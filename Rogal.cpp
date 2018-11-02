/*
	Maciej Gabryś
	gm41357, gr. 211a

	02.11.2018
*/

#include <ncurses.h>
#include <iostream>
#include <string>
#include "Enumerations.h"
#include "Area.h"
#include "Coin.h"
#include "Map.h"
#include "Player.h"
#include "Exceptions.h"

void init();
bool play_level(std::string path, Player& player);
void quit();

int main()
{
	init();
	Player player;
	std::ifstream list;
	std::string path;
	list.open("List.txt");
	while (list >> path)
	{
		if (play_level(path, player) == false)
		{
			break;
		}
	}
	list.close();
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
	//        v- numery jako enum
	init_pair(1, COLOR_BLUE, -1); //ściany
	init_pair(2, COLOR_WHITE, -1); //podłogi
	init_pair(3, COLOR_CYAN, -1); //ścieżki
	init_pair(4, COLOR_RED, -1); //gracz
	init_pair(5, COLOR_YELLOW, -1); //pieniądze
}

bool play_level(std::string path, Player& player)
{
	Map* map;
	try
	{
		map = new Map{ path };
	}
	catch (Exception& e)
	{
		erase();
		printw("%s", e.what());
		getch();
		return false;
	}
	player.teleport(map);
	while (map->remaining_coins() > 0)
	{
		erase();
		map->display();
		move(0, 0);
		printw("Level \"%s\", coins=%d, left=%d", path.c_str(), player.get_amount(), map->remaining_coins());
		player.display();
		switch (getch())
		{
		case 'a':
			player.walk(map, direction_left);
			break;
		case 'd':
			player.walk(map, direction_right);
			break;
		case 'w':
			player.walk(map, direction_up);
			break;
		case 's':
			player.walk(map, direction_down);
			break;
		case 'q':
			delete map;
			return false;
		}
	}
	delete map;
	return true;
}

void quit()
{
	endwin();
}

