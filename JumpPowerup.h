#pragma once
#include "Powerup.h"

class JumpPowerup : public Powerup
{
public:
	JumpPowerup(sf::Texture* texture, sf::Vector2f position);
	~JumpPowerup();
};

