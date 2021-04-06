#pragma once
#include "Enemy.h"

class FastAttackEnemy : public Enemy
{
public:
	FastAttackEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr);
	~FastAttackEnemy();

	void UpdateAnimation();
};

