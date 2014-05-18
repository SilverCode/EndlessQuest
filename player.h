#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "object.h"

class Player : public Object
{
	private:
		SDL_Texture *playerTexture;
		int width;
		int height;

	public:
		Player();
		~Player();

		bool init();
		void render(SDL_Renderer *renderer);
};

#endif // PLAYER_H
