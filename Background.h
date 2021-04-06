#pragma once
#include <SFML/Graphics.hpp>

class Background
{
private:
	sf::Sprite backgroundImage;

public:
	Background(sf::Texture& texture);
	void Draw(sf::RenderWindow& window);
};

