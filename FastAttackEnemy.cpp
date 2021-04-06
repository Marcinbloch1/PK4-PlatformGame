#include "FastAttackEnemy.h"

FastAttackEnemy::FastAttackEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr) :
	Enemy(texture, imageCount, switchTime, position, boundXl, boundXr)
{
	this->speed = FAST_ATTACK_ENEMY_SPEED;
	this->boundXl = boundXl;
	this->boundXr = boundXr;
	this->isAbleToJump = false;
	body.setSize(sf::Vector2f(ENEMY2_SIZE_X, ENEMY2_SIZE_Y));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

FastAttackEnemy::~FastAttackEnemy()
{
}

void FastAttackEnemy::UpdateAnimation()
{
	if (velocity.x == 0.0f)
	{
		row = 1;
	}
	else
	{
		row = 0;

		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}
}
