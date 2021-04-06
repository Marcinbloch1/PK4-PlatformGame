#include "Powerup.h"

Powerup::Powerup(sf::Texture* texture, sf::Vector2f position) :
	DrawableObjects(texture, position),
	size(sf::Vector2f(POWERUP_SIZE_X, POWERUP_SIZE_Y))
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
}

Powerup::~Powerup()
{
}
