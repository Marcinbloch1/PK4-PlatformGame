#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f position) :
	DrawableObjects(texture, position),
	size(sf::Vector2f(PLATFORM_SIZE_X, PLATFORM_SIZE_Y))
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
}

Platform::~Platform()
{
}
