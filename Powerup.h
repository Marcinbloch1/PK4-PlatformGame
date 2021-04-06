#pragma once
#include "DrawableObjects.h"

class Powerup : public DrawableObjects
{
private:
	sf::Vector2f size;

public:
	Powerup(sf::Texture* texture, sf::Vector2f position);
	~Powerup();
};

