#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Definitions.h"

class Hud
{
private:
	int score;
	int coinValue;
	int lives;
	int hitValue;
	int jump;
	int speed;
	sf::Font font;
	sf::Text scoreText;
	sf::Text livesText;
	sf::Text jumpHeightText;
	sf::Text speedText;
	sf::Text loseText;
	sf::Text winText;

public:
	Hud();
	~Hud();

	void Update(sf::View view);
	void Update_score();
	void Update_lives();
	void Update_jump(float jumpHeight);
	void Update_speed(float speed);
	void Update_lose(sf::RenderWindow& window);
	void Update_win(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	int getLives();
	int getScore();
};