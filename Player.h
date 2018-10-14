#pragma once
#include "Entity.h"
#include "Map.h"
#include <utility>

class Player :
	public Entity
{
private:
	unsigned int amount;
public:
	Player();
	void teleport(Map* map);
	void walk(Map* map, int sx, int sy);
	unsigned int get_amount();
	void display() override;
	~Player() override;
};

