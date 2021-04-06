#include "Floor.h"

Floor::Floor(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) :
	DrawableObjects(texture, position)
{
	body.setSize(size);
}

Floor::~Floor()
{
}