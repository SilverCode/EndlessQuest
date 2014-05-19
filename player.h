/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "object.h"
#include "weapon.h"

class Player : public Object
{
	private:
		SDL_Texture *playerTexture;
		int width;
		int height;
		Weapon *weapon;

		void handleInput();

	public:
		Player();
		~Player();

		bool init();
		void render(SDL_Renderer *renderer);
		void update();
};

#endif // PLAYER_H
