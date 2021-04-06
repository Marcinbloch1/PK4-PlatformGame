#include "Coin.h"

Coin::Coin(sf::Texture* texture, sf::Vector2f position) :
	DrawableObjects(texture, position),
	size(sf::Vector2f(COIN_SIZE_X, COIN_SIZE_Y))
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
}

Coin::~Coin()
{
}

