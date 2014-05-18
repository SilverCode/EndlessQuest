#include "object.h"

Object::Object() :
	position(0, 0),
	velocity(0, 0),
	acceleration(0, 0)
{
}

void Object::update()
{
	velocity += acceleration;
	position += velocity;
}
