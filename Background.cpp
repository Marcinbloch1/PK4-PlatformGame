#include "Background.h"

Background::Background(sf::Texture& texture)
{
	backgroundImage.setTexture(texture);
	backgroundImage.setTextureRect(sf::IntRect(-1000, -1000, 20000, 20000));
	backgroundImage.setPosition(-5000, -4000);
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundImage);
}
