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
	void walk(Map* map, directions direction) noexcept;
	inline unsigned int get_amount() noexcept
	{
		return amount;
	}
	void display() noexcept override;
	~Player() noexcept override;
};

