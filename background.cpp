/*
 * Copyright (c) 2014 Ross Simpson
 * All Right Reserved
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license,visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
 */

#include "background.h"
#include "gamestate.h"

#include <SDL2/SDL_image.h>
#include <string>
#include <time.h>

using namespace std;

void Background::genStars()
{
	static const uint32_t maxStars = 100;

	srand(time(NULL));

	// Generate our intiail start pattern
	for (size_t i = 0; i < maxStars; i++)
	{
		Vector2D tmpStar(0, 0);
		tmpStar.setX(rand() % GameState::get()->getWindowWidth());
		tmpStar.setY(rand() % GameState::get()->getWindowHeight());
		stars.push_back(tmpStar);
	}
}

Background::~Background()
{
	SDL_DestroyTexture(backgroundTexture);
}

bool Background::init()
{
	// TODO: Really, really implement a texture handler
	const string backgroundTextureFile = "/home/rsimpson/Development/EndlessQuest/images/nebula2.png";
	backgroundTexture = IMG_LoadTexture(GameState::get()->getRenderer(), backgroundTextureFile.c_str());

	if (backgroundTexture == nullptr)
	{
		logSDLError(cout, "Background::init(), IMG_LoadTexture");
		return false;
	}

	genStars();

	return true;
}

void Background::update()
{
	Vector2D velocity(0, 1);

	for (vector<Vector2D>::iterator star = stars.begin(); star != stars.end(); ++star)
	{
		*star += velocity;

		// If the star has gone off the screen, respawn at random location
		// at the top
		if (star->getY() > GameState::get()->getWindowHeight())
		{
			star->setY(0);
			star->setX(rand() % GameState::get()->getWindowWidth());
		}
	}
}

void Background::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (vector<Vector2D>::iterator star = stars.begin(); star != stars.end(); ++star)
	{
		SDL_RenderDrawPoint(renderer, star->getX(), star->getY());
	}
}
