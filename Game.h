#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <memory>
#include "Player.h"
#include "Platform.h"
#include "MovingPlatform.h"
#include "Floor.h"
#include "Coin.h"
#include "Powerup.h"
#include "JumpPowerup.h"
#include "SpeedPowerup.h"
#include "Enemy.h"
#include "JumpingEnemy.h"
#include "FastAttackEnemy.h"
#include "Textures.h"
#include "Hud.h"
#include "Background.h"
#include "Definitions.h"
#include "Functions.h"
#include "SceneLoad.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::View view;
	sf::View viewHud;
	Textures texture;
	Player player;
	Background background;
	std::vector<std::shared_ptr<DrawableObjects>> drawableobjects;
	std::vector<std::shared_ptr<Enemy>> enemies;
	Hud hud;
	float deltaTime = 0.0f;
	sf::Clock clock;
	int coinAmount;
	sf::Event event;

public:
	Game(int level);
	~Game();

	void GameLoop();

private:
	void LoadLevel_1();
	void LoadLevel_2();
	void LoadLevel_3();
	int CountCoinObjects();
	void EventHandler();
	void UpdateDrawable();
	void CheckCollision();
	void DestroyObjects();
	void ViewHandler();
	void DrawObjects();
	void HudViewHandler();
	void DrawHud();
	void WindowDisplay();
	void EndGame(sf::Event event);
	void ExitGame();
};