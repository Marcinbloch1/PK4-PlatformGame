#pragma once
#include "Platform.h"
#include "Definitions.h"

class MovingPlatform : public Platform
{
private:
	sf::Vector2f velocity;
	float speed;

	int direction;
	int counterTwo;
	bool isXaxis;
	float bound1;
	float bound2;

public:
	MovingPlatform(sf::Texture* texture, sf::Vector2f position, bool isXaxis, float bound1, float bound2);
	~MovingPlatform();
	void Update(float deltaTime);
};

