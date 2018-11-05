#include "Entity.h"

Entity::Entity(int x, int y)
{
	set_coordinates(x, y);
}

void Entity::set_coordinates(int x, int y)
{
	if (x < 0 || y < 0)
	{
		throw(ExceptionWrongCoordinates{ x, y });
	}
	this->x = x;
	this->y = y;
}

bool Entity::is_this_you(int tx, int ty)
{
	if (tx == x && ty == y)
	{
		return true;
	}
	return false;
}

Entity::~Entity()
{
}

