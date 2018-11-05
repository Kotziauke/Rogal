#pragma once
#include "Constants.h"
#include "Entity.h"
#include "Map.h"
#include <utility>

class Player :
	public Entity
{
private:
	unsigned int amount = 0;
public:
	Player();
	void teleport(Map* map);
	void walk(Map* map, directions direction);
	inline unsigned int get_amount()
	{
		return amount;
	}
	void display() override;
	~Player() override;
};

