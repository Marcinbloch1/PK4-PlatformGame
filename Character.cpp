#include "Character.h"

Character::Character(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	animation(texture, imageCount, switchTime),
	canJump(false),
	jumpHeight(0.0f),
	speed(0.0f)
{
	row = 0;
	faceRight = true;
}

Character::~Character()
{
}


void Character::Update(float deltaTime)
{
}

void Character::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Character::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}