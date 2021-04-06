#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableObjects.h"

class Coin : public DrawableObjects
{
private:
	sf::Vector2f size;

public:
	bool isCoin = true;

public:
	Coin(sf::Texture* texture, sf::Vector2f position);
	~Coin();
};