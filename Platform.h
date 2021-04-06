#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableObjects.h"

class Platform : public DrawableObjects
{
private:
	sf::Vector2f size;

public:
	Platform(sf::Texture* texture, sf::Vector2f position);
	~Platform();
};

