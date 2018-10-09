#include "Entity.h"

Entity::Entity(unsigned int x, unsigned int y) :
	x { x },
	y { y }
{
}

bool Entity::is_this_you(unsigned int tx, unsigned int ty)
{
	if(tx == x && ty == y)
	{
		return true;
	}
	return false;
}

Entity::~Entity()
{
}

