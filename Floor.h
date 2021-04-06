#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableObjects.h"
#include "Definitions.h"

class Floor : public DrawableObjects
{
public:
	Floor(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Floor();
};

