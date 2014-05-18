#include "weapon.h"
#include "gamestate.h"

#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

bool StandardLaserWeapon::init()
{
	// TODO: TEXTURE HANDLER!
	// The strong argument for implementing a texture handler NOW, is because if this
	// weapon is swapped out, the destructor will be called, freeing the bullet texture,
	// meaning that all bullets currently on screen using the texture will not render
	const string bulletTextureFile = "/home/rsimpson/Development/EndlessQuest/images/laser.png";
	bulletTexture = IMG_LoadTexture(GameState::get()->getRenderer(), bulletTextureFile.c_str());

	if (bulletTexture == nullptr)
	{
		logSDLError(cout, "Background::init(), IMG_LoadTexture");
		return false;
	}

	return true;
}

void StandardLaserWeapon::update()
{
	Vector2D velocity(0, -5);

	// TODO: Clean up bullet when it exits screen
	for (vector<Vector2D*>::iterator bullet = bullets.begin(); bullet != bullets.end(); ++bullet)
	{
		Vector2D *tmpBullet = (*bullet);
		*tmpBullet += velocity;
	}
}

void StandardLaserWeapon::fire(Vector2D shipPosition)
{
	// TODO: Implement a rate of fire for weapons
	Vector2D *bullet1 = new Vector2D(0, 0);
	bullet1->setX(shipPosition.getX());
	bullet1->setY(shipPosition.getY());
	bullets.push_back(bullet1);

	Vector2D *bullet2 = new Vector2D(0, 0);
	bullet2->setX(shipPosition.getX()+50);
	bullet2->setY(shipPosition.getY());
	bullets.push_back(bullet2);
}

StandardLaserWeapon::~StandardLaserWeapon()
{
	SDL_DestroyTexture(bulletTexture);
}

void StandardLaserWeapon::render(SDL_Renderer *renderer)
{
	for (vector<Vector2D*>::iterator bullet = bullets.begin(); bullet != bullets.end(); ++bullet)
	{
		Vector2D *tmpBullet = (*bullet);
		SDL_Rect dest;
		dest.x = tmpBullet->getX();
		dest.y = tmpBullet->getY();
		dest.w = 48;
		dest.h = 82;
		SDL_RenderCopy(renderer, bulletTexture, NULL, &dest);
	}
}
