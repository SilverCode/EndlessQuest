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

		void render(SDL_Renderer* renderer);
		bool init();
		void update();
};

#endif // BACKGROUND_H
