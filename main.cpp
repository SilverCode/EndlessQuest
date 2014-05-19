/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "gamestate.h"

using namespace std;

const uint32_t FPS = 60;
const uint32_t DELAY_TIME = 1000.0f / FPS;

int main()
{
	if (GameState::get()->init("EndlessQuest"))
	{
		uint32_t frameStart, frameTime;

		while (GameState::get()->isRunning())
		{
			frameStart = SDL_GetTicks();

			GameState::get()->handleEvents();
			GameState::get()->update();
			GameState::get()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)DELAY_TIME - frameTime);
			}
		}
	}
	else
	{
		cout << "Failed to initialize Game State" << endl;
	}

	GameState::get()->destroy();

	return 0;
}
