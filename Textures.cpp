#include "Textures.h"

Textures::Textures()
{
	loadAllTextures();
}

void Textures::loadTexture(TEXTURES id, std::string filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());

	if (!texture->loadFromFile(filename))
		throw std::runtime_error("Texture failed to load: " + filename);

	if (id == TEXTURES::BACKGROUND_TEXTURE)
	{
		texture->setRepeated(true);
		texture->setSmooth(true);
	}

	auto is_inserted = textures_map.insert(std::pair<TEXTURES, std::unique_ptr<sf::Texture>>(id, std::move(texture)));
	assert(("Texture " + filename + "was loaded more than once", is_inserted.second));
}

sf::Texture& Textures::getTexture(const TEXTURES& id)
{
	auto search = textures_map.find(id);

	assert(("Eror with texture", search != textures_map.end()));
	return *search->second;
}

void Textures::loadAllTextures()
{
	loadTexture(TEXTURES::PLAYER_TEXTURE, "Textures/player.png");
	loadTexture(TEXTURES::ENEMY_TEXTURE_1, "Textures/jumpingenemy.png");
	loadTexture(TEXTURES::ENEMY_TEXTURE_2, "Textures/fastenemy.png");
	loadTexture(TEXTURES::PLATFORM_TEXTURE, "Textures/platform_dirt.png");
	loadTexture(TEXTURES::BACKGROUND_TEXTURE, "Textures/background_sky.jpg");
	loadTexture(TEXTURES::COIN_TEXTURE, "Textures/coin_mario.png");
	loadTexture(TEXTURES::JUMPPOWERUP_TEXTURE, "Textures/jumppowerup.png");
	loadTexture(TEXTURES::SPEEDPOWERUP_TEXTURE, "Textures/speedpowerup.png");
}