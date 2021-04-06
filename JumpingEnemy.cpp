#include "JumpingEnemy.h"

JumpingEnemy::JumpingEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr) :
	Enemy(texture, imageCount, switchTime, position, boundXl, boundXr)
{
	this->speed = JUMPING_ENEMY_SPEED;
	this->jumpHeight = JUMPING_ENEMY_JUMP_HEIGHT;
	this->boundXl = boundXl;
	this->boundXr = boundXr;
	this->isAbleToJump = true;
	body.setSize(sf::Vector2f(ENEMY1_SIZE_X, ENEMY1_SIZE_Y));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
}

JumpingEnemy::~JumpingEnemy()
{
}

void JumpingEnemy::UpdateAnimation()
{
	if (velocity.x == 0.0f)
	{
		row = 1;
	}
	else
	{
		if (velocity.x > 0.0f)
		{
			row = 2;
			faceRight = true;
		}
		else
		{
			row = 0;
			faceRight = true;
		}
	}
}
