#pragma once
#include "Enemy.h"

class JumpingEnemy : public Enemy
{
public:
	JumpingEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr);
	~JumpingEnemy();

	void UpdateAnimation();
};

