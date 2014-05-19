/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

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
