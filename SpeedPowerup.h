#pragma once
#include "Powerup.h"

class SpeedPowerup : public Powerup
{
public:
	SpeedPowerup(sf::Texture* texture, sf::Vector2f position);
	~SpeedPowerup();
};

