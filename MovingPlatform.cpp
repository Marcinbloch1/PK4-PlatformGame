#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(sf::Texture* texture, sf::Vector2f position, bool isXaxis, float bound1, float bound2) :
	Platform(texture, position),
	speed(MOVING_PLATFORM_SPEED), direction(1), counterTwo(1)
{
	this->isXaxis = isXaxis;
	this->bound1 = bound1;
	this->bound2 = bound2;
}

MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::Update(float deltaTime)
{
	if (isXaxis)
	{
		velocity.x *= 0.5f;

		if (direction == 1)	//left
			velocity.x -= speed;
		if (direction == 2)	//right
			velocity.x += speed;

		if (body.getPosition().x <= bound1 && counterTwo == 1)
		{
			direction = 2;
			counterTwo = 2;
		}
		else if (counterTwo == 2)
		{
			if (body.getPosition().x >= bound2)
			{
				direction = 1;
				counterTwo = 1;
			}
		}
	}
	else if (!isXaxis)
	{
		velocity.y *= 0.5f;

		if (direction == 1)	//up
			velocity.y -= speed;
		if (direction == 2)	//up
			velocity.y += speed;

		if (body.getPosition().y <= bound1 && counterTwo == 1)
		{
			direction = 2;
			counterTwo = 2;
		}
		else if (counterTwo == 2)
		{
			if (body.getPosition().y >= bound2)
			{
				direction = 1;
				counterTwo = 1;
			}
		}
	}
	

	body.move(velocity * deltaTime);
}
