#pragma once
#include "Entity.h"

class Player :
	public Entity
{
	friend class Map;
private:
	unsigned int amount;
public:
	Player();
	void respawn();
	unsigned int get_amount();
	void display() override;
	~Player() override;
};

