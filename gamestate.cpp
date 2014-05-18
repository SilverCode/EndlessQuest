#include "gamestate.h"
#include "player.h"

#include <SDL2/SDL_image.h>

using namespace std;

GameState* GameState::instance = nullptr;

GameState::GameState()
{
	window = nullptr;
	renderer = nullptr;
	windowWidth = 0;
	windowHeight = 0;
	running = true;
}

void GameState::initObjects()
{
	Player* player = new Player();
	player->init();

	objects.push_back(player);
}

void GameState::destroyObjects()
{
	for (size_t i = objects.size()-1; i != 0; i++)
	{
		delete objects[i];
	}
}

bool GameState::init(string title, int width, int height)
{
	this->windowWidth = width;
	this->windowHeight = height;

	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
	{
		logSDLError(cout, "SDL_Init");
		return false;
	}

	// Initialize SDL_Image with only PNG loading, and check it actully succeeded
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		logSDLError(cout, "IMG_Init");
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), 0, 0, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		logSDLError(cout, "CreateWindow");
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		logSDLError(cout, "CreateRenderer");
		return false;
	}

	initObjects();

	return true;
}

void GameState::destroy()
{
	destroyObjects();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameState::update()
{
	for (vector<Object*>::iterator object = objects.begin(); object != objects.end(); ++object)
	{
		Object *tmpObject = (*object);
		tmpObject->update();
	}
}

void GameState::render()
{
	SDL_RenderClear(renderer);

	for (vector<Object*>::iterator object = objects.begin(); object != objects.end(); ++object)
	{
		Object *tmpObject = (*object);
		tmpObject->render(renderer);
	}

	SDL_RenderPresent(renderer);
}

void GameState::handleEvents()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		if (sdlEvent.type == SDL_QUIT)
			running = false;
	}
}

void logSDLError(ostream &os, const string &msg)
{
	os << msg << " error: " << SDL_GetError() << endl;
}
