#include "Entity.h"

Entity::Entity(int x, int y)
{
	set_coordinates(x, y);
}

void Entity::set_coordinates(int sx, int sy)
{
	if (sx < 0 || sy < 0)
	{
		throw ExceptionWrongCoordinates{ sx, sy };
	}
	x = sx;
	y = sy;
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

