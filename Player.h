#pragma once
#include "Enumerations.h"
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
	void walk(Map* map, directions direction);
	unsigned int get_amount();
	void display() override;
	~Player() override;
};

