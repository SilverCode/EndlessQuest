#include "background.h"
#include "gamestate.h"

#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Background::Background()
{
}

bool Background::init()
{
	// TODO: Really, really implement a texture handler
	const string backgroundTextureFile = "/home/rsimpson/Development/EndlessQuest/images/nebula.png";
	backgroundTexture = IMG_LoadTexture(GameState::get()->getRenderer(), backgroundTextureFile.c_str());

	if (backgroundTexture == nullptr)
	{
		logSDLError(cout, "Background::init(), IMG_LoadTexture");
		return false;
	}

	// TODO: generate star pattern;

	return true;
}

void Background::update()
{
	// TODO: Update the stars
}

void Background::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}
