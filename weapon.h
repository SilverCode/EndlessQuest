/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <vector>

#include "object.h"

class Weapon
{
	public:
		Weapon() {}
		virtual ~Weapon() {}

		virtual void update() = 0;
		virtual void fire(Vector2D shipPosition) = 0;
		virtual bool init() = 0;
		virtual void render(SDL_Renderer *renderer) = 0;
};

class StandardLaserWeapon : public Weapon
{
	private:
		SDL_Texture *bulletTexture;
		std::vector<Vector2D*> bullets;

	public:
		StandardLaserWeapon() {}
		~StandardLaserWeapon();
		bool init();
		void update();
		void render(SDL_Renderer *renderer);
		void fire(Vector2D shipPosition);
};

#endif // WEAPON_H
