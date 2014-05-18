#include "player.h"
#include "gamestate.h"

#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

Player::Player()
{
}

Player::~Player()
{
	if (playerTexture != nullptr)
		SDL_DestroyTexture(playerTexture);
}

bool Player::init()
{
	// TODO: Implement texture manager
	const string playerTextureFile = "/home/rsimpson/Development/EndlessQuest/images/destroyer.png";
	playerTexture = IMG_LoadTexture(GameState::get()->getRenderer(), playerTextureFile.c_str());

	if (playerTexture == nullptr)
	{
		logSDLError(cout, "Player::init(), IMG_LoadTexture");
		return false;
	}

	// Scale the image down, as the source is pretty darn big
	SDL_QueryTexture(playerTexture, NULL, NULL, &width, &height);
	width = width/4;
	height = height/4;

	return true;
}

void Player::render(SDL_Renderer *renderer)
{
	SDL_Rect dest;
	dest.x = position.getX();
	dest.y = position.getY();
	dest.w = width;
	dest.h = height;
	SDL_RenderCopy(renderer, playerTexture, NULL, &dest);
}

void Player::handleInput()
{
	const uint8_t* keyState = SDL_GetKeyboardState(NULL);

	float accelX = acceleration.getX();
	float accelY = acceleration.getY();

	if (keyState[SDL_SCANCODE_RIGHT])
	{
		accelX = accelX == 0 ? 0.5 : 0;
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		accelX = accelX == 0 ? -0.5 : 0;
	}
	else
	{
		accelX = 0;
	}

	if(keyState[SDL_SCANCODE_UP])
	{
		accelY = accelY == 0 ? -0.5 : 0;
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		accelY = accelY == 0 ? 0.5 : 0;
	}
	else
	{
		accelY = 0;
	}

	acceleration.setX(accelX);
	acceleration.setY(accelY);
}

void Player::update()
{
	handleInput();
	Object::update();
}
