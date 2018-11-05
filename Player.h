#pragma once
#include <utility>
#include "Entity.h"
#include "Constants.h"
#include "Map.h"

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

