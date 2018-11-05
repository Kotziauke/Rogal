#pragma once
#include "Entity.h"

class Coin :
	public Entity
{
public:
	Coin(int x, int y);
	void display() override;
	~Coin() override;
};

