/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>

#include "vector2d.h"

class Object
{
	protected:
		Vector2D position;
		Vector2D velocity;
		Vector2D acceleration;

	public:
		Object();
		virtual ~Object() {}

		virtual void update() = 0;
		virtual bool init() = 0;
		virtual void render(SDL_Renderer *renderer) = 0;
};

#endif // OBJECT_H
