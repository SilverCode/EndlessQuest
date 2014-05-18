#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <vector>

#include "object.h"
#include "background.h"

class GameState
{
	private:
		GameState();
		static GameState* instance;

		SDL_Window *window;
		SDL_Renderer *renderer;
		int windowWidth;
		int windowHeight;

		std::vector<Object*> objects;
		Background *background;

		void initObjects();
		void destroyObjects();

		bool running;

	public:
		static GameState* get()
		{
			if (instance == nullptr)
				instance = new GameState();

			return instance;
		}

		bool init(std::string title, int width = 1280, int height = 720);
		void destroy();
		void update();
		void render();
		void handleEvents();

		int getWindowWidth() { return windowWidth; }
		int getWindowHeight() { return windowHeight; }
		SDL_Renderer* getRenderer() const { return renderer; }
		bool isRunning() { return running; }
};

// TODO: Move into separate logging class
void logSDLError(std::ostream &os, const std::string &msg);

#endif // GAMESTATE_H
