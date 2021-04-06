#include "Hud.h"

Hud::Hud() :
	score(0), coinValue(COIN_VALUE), lives(LIVES), hitValue(HIT_VALUE), jump((int)PLAYER_JUMP_HEIGHT), speed((int)PLAYER_SPEED)
{
	std::string caviar_font = "Fonts/CaviarDreams.ttf";
	if (!font.loadFromFile(caviar_font))
		throw std::runtime_error("Font failed to load: " + caviar_font);

	scoreText.setFont(font);
	scoreText.setString("Your score: " + std::to_string(score));
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::Black);

	livesText.setFont(font);
	livesText.setString("Your lives: " + std::to_string(lives));
	livesText.setCharacterSize(24);
	livesText.setFillColor(sf::Color::Black);

	jumpHeightText.setFont(font);
	jumpHeightText.setString("Your jump: " + std::to_string(jump));
	jumpHeightText.setCharacterSize(24);
	jumpHeightText.setFillColor(sf::Color::Black);

	speedText.setFont(font);
	speedText.setString("Your speed: " + std::to_string(speed));
	speedText.setCharacterSize(24);
	speedText.setFillColor(sf::Color::Black);
}

Hud::~Hud()
{
}

void Hud::Update(sf::View view)
{
	scoreText.setPosition(view.getCenter().x - SCORE_TEXT_X, view.getCenter().y - SCORE_TEXT_Y);
	livesText.setPosition(view.getCenter().x - LIVES_TEXT_X, view.getCenter().y - LIVES_TEXT_Y);
	jumpHeightText.setPosition(view.getCenter().x - JUMP_TEXT_X, view.getCenter().y - JUMP_TEXT_Y);
	speedText.setPosition(view.getCenter().x - SPEED_TEXT_X, view.getCenter().y - SPEED_TEXT_Y);
}

void Hud::Update_score()
{
	score += coinValue;
	scoreText.setString("Your score: " + std::to_string(score));
}

void Hud::Update_lives()
{
	lives -= hitValue;
	livesText.setString("Your lives: " + std::to_string(lives));
}

void Hud::Update_jump(float jumpHeight)
{
	jump = (int)jumpHeight;
	jumpHeightText.setString("Your jump: " + std::to_string(jump));
}

void Hud::Update_speed(float speed)
{
	this->speed = (int)speed;
	speedText.setString("Your speed: " + std::to_string(this->speed));
}

void Hud::Update_lose(sf::RenderWindow& window)
{
	loseText.setFont(font);
	loseText.setString("You lost \nYour score: " + std::to_string(score) + "\nPress ENTER to close");
	loseText.setCharacterSize(24);
	loseText.setFillColor(sf::Color::Black);
	loseText.setOrigin(loseText.getLocalBounds().width / 2, loseText.getLocalBounds().height / 2);
	loseText.setPosition(window.getView().getCenter().x, window.getView().getCenter().y);
	window.draw(loseText);
}

void Hud::Update_win(sf::RenderWindow& window)
{
	winText.setFont(font);
	winText.setString("You won \nYour score: " + std::to_string(score) + "\nPress ENTER to close");
	winText.setCharacterSize(24);
	winText.setFillColor(sf::Color::Black);
	winText.setOrigin(winText.getLocalBounds().width / 2, winText.getLocalBounds().height / 2);
	winText.setPosition(window.getView().getCenter().x, window.getView().getCenter().y);
	window.draw(winText);
}

void Hud::Draw(sf::RenderWindow& window)
{
	window.draw(scoreText);
	window.draw(livesText);
	window.draw(jumpHeightText);
	window.draw(speedText);
}

int Hud::getLives()
{
	return lives;
}

int Hud::getScore()
{
	return score;
}
