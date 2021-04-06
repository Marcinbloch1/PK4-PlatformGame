#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include"Definitions.h"

class DrawableObjects
{
protected:
	sf::RectangleShape body;

public:
	bool destroyed = false;

public:
	DrawableObjects(sf::Texture* texture, sf::Vector2f position);
	virtual ~DrawableObjects();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
};