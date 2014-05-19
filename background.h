/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>
#include <vector>

#include "vector2d.h"

class Background
{
	private:
		SDL_Texture* backgroundTexture;
		std::vector<Vector2D > stars;

		void genStars();

	public:
		Background() {}
		~Background();

		void render(SDL_Renderer* renderer);
		bool init();
		void update();
};

#endif // BACKGROUND_H
