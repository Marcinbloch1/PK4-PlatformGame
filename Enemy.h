#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"


class Enemy : public Character
{
protected:
	int direction=1;
	int counterTwo=1;
	float boundXl, boundXr;
	bool isAbleToJump;

public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float boundXl, float boundXr);
	virtual ~Enemy();

	void Update(float deltaTime);
	virtual void UpdateAnimation();
};