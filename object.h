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

		void update();

		virtual bool init() = 0;
		virtual void render(SDL_Renderer *renderer) = 0;
};

#endif // OBJECT_H
