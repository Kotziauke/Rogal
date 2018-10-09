#pragma once
#include "Entity.h"
#include <string>

class Coin :
	public Entity
{
public:
	Coin(unsigned int x, unsigned int y);
	void display() override;
	~Coin() override;
};

