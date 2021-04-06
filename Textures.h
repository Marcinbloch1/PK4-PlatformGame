#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Textures
{
private:
	std::map<TEXTURES, std::unique_ptr<sf::Texture>> textures_map;

public:
	Textures();
	void loadTexture(TEXTURES id, std::string filename);
	sf::Texture& getTexture(const TEXTURES& id);

private:
	void loadAllTextures();
	
};

