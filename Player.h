#pragma once
#include "Entity.h"
#include "Map.h"

class Player :
	public Entity
{
private:
	unsigned int amount;
public:
	Player();
	void respawn();
	void walk(Map& map, int sx, int sy);
	unsigned int get_amount();
	void display() override;
	~Player() override;
};

