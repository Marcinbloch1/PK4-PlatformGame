#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	Character(texture, imageCount, switchTime)
{
	this->speed = PLAYER_SPEED;
	this->jumpHeight = PLAYER_JUMP_HEIGHT;
	body.setSize(sf::Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
		sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) <= -50 ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) <=-100)
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
		sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) >= 50 ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) >= 100)
		velocity.x += speed;

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || 
		sf::Joystick::isButtonPressed(0, 0)) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}
	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
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
			row = 1;
			faceRight = true;
		}
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::LoadCheckpoint(sf::Vector2f position)
{
	body.setPosition(position);
}

void Player::setJumpHeight(float JUMP_POWERUP_VALUE)
{
	this->jumpHeight += JUMP_POWERUP_VALUE;
}

void Player::setSpeed(float SPEED_POWERUP_VALUE)
{
	this->speed += SPEED_POWERUP_VALUE;
}

float Player::getJumpHeight()
{
	return this->jumpHeight;
}

float Player::getSpeed()
{
	return this->speed;
}
