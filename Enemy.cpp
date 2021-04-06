#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr) :
	Character(texture, imageCount, switchTime),
	boundXl(0.0f),
	boundXr(0.0f),
	isAbleToJump(false)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	velocity.x *= 0.5f;

	if (direction==1)	//left
		velocity.x -= speed;	
	if (direction==2)	//right
		velocity.x += speed;

	if (isAbleToJump == true)
	{
		if ((rand() % 1000) == 0 && canJump)
		{
			canJump = false;
			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}
	}
	velocity.y += 981.0f * deltaTime;

	if(body.getPosition().x<=boundXl && counterTwo==1)
	{
		direction = 2;
		counterTwo = 2;
	}
	else if ( counterTwo == 2)
	{
		if(body.getPosition().x >= boundXr)
		{
			direction = 1;
			counterTwo = 1;
		}
	}


	UpdateAnimation();

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Enemy::UpdateAnimation()
{
}
