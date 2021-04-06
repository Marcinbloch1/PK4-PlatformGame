#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

class Player : public Character
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Player();

	void Update(float deltaTime);
	void LoadCheckpoint(sf::Vector2f position);

	void setJumpHeight(float JUMP_POWERUP_VALUE);
	void setSpeed(float SPEED_POWERUP_VALUE);
	float getJumpHeight();
	float getSpeed();
};
