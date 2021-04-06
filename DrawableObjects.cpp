#include "DrawableObjects.h"

DrawableObjects::DrawableObjects(sf::Texture* texture, sf::Vector2f position)
{
	body.setTexture(texture);
	body.setPosition(position);
}

DrawableObjects::~DrawableObjects()
{
}

void DrawableObjects::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
