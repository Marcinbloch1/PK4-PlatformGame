#include "Game.h"

Game::Game(int level) :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platform Game"),
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
	viewHud(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
	player(&texture.getTexture(TEXTURES::PLAYER_TEXTURE), sf::Vector2u(4, 4), 0.3f),
	background(texture.getTexture(TEXTURES::BACKGROUND_TEXTURE)),
	coinAmount(0)
{
	window.setFramerateLimit(240);

	if (level == 1)
	{
		LoadLevel_1();
	}
	else if (level == 2)
	{
		LoadLevel_2();
	}
	else if (level == 3)
	{
		LoadLevel_3();
	}
	coinAmount = CountCoinObjects();
}

Game::~Game()
{
}

void Game::GameLoop()
{
	while (window.isOpen())
	{
		EventHandler();
		UpdateDrawable();
		CheckCollision();
		DestroyObjects();
		ViewHandler();
		DrawObjects();
		HudViewHandler();
		DrawHud();
		WindowDisplay();
		EndGame(event);
	}
}

void Game::LoadLevel_1()
{
	CHECKPOINT_X = LEVEL1_STARTING_POINT_X;
	CHECKPOINT_Y = LEVEL1_STARTING_POINT_Y;
	player.LoadCheckpoint(sf::Vector2f(LEVEL1_STARTING_POINT_X, LEVEL1_STARTING_POINT_Y));
	SceneLoad scene;
	scene.LoadLevel_1(drawableobjects, enemies, texture);
	hud.Update(viewHud);
}

void Game::LoadLevel_2()
{
	CHECKPOINT_X = LEVEL2_STARTING_POINT_X;
	CHECKPOINT_Y = LEVEL2_STARTING_POINT_Y;
	player.LoadCheckpoint(sf::Vector2f(LEVEL2_STARTING_POINT_X, LEVEL2_STARTING_POINT_Y));
	SceneLoad scene;
	scene.LoadLevel_2(drawableobjects, enemies, texture);
	hud.Update(viewHud);
}

void Game::LoadLevel_3()
{
	CHECKPOINT_X = LEVEL3_STARTING_POINT_X;
	CHECKPOINT_Y = LEVEL3_STARTING_POINT_Y;
	player.LoadCheckpoint(sf::Vector2f(LEVEL3_STARTING_POINT_X, LEVEL3_STARTING_POINT_Y));
	SceneLoad scene;
	scene.LoadLevel_3(drawableobjects, enemies, texture);
	hud.Update(viewHud);
}

int Game::CountCoinObjects()
{
	int count = 0;
	for (auto& drawableobject : drawableobjects)
	{
		if (std::shared_ptr<Coin> movingplatform = std::dynamic_pointer_cast<Coin>(drawableobject))
		{
			count++;
		}
	}
	return count;
}

void Game::EventHandler()
{
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 30.0f)
		deltaTime = 1.0f / 30.0f;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::JoystickButtonPressed)
		{
			if (event.joystickButton.button == sf::Joystick::PovX ||
				event.joystickButton.button == sf::Joystick::PovY)
			{
				window.close();
			}
		}
		if (event.type == sf::Event::Resized)
		{
			ResizeView(window, view);
		}
	}
}

void Game::UpdateDrawable()
{
	player.Update(deltaTime);

	for (auto& drawableobject : drawableobjects)
	{
		if (std::shared_ptr<MovingPlatform> movingplatform = std::dynamic_pointer_cast<MovingPlatform>(drawableobject))
		{
			movingplatform->Update(deltaTime);
		}
	}

	for (auto& enemy : enemies)
	{
		if (std::shared_ptr<JumpingEnemy> jumpingenemy = std::dynamic_pointer_cast<JumpingEnemy>(enemy))
			jumpingenemy->Update(deltaTime);

		else if (std::shared_ptr<FastAttackEnemy> fastattackenemy = std::dynamic_pointer_cast<FastAttackEnemy>(enemy))
			fastattackenemy->Update(deltaTime);
	}
}

void Game::CheckCollision()
{
	sf::Vector2f direction;

	for (auto& drawableobject : drawableobjects)
	{
		Collider playerCollision = player.GetCollider();
		if (drawableobject->GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			if (std::shared_ptr<Coin> coin = std::dynamic_pointer_cast<Coin>(drawableobject))
			{
				hud.Update_score();
				drawableobject->destroyed = true;
			}
			else if (std::shared_ptr<JumpPowerup> jumppowerup = std::dynamic_pointer_cast<JumpPowerup>(drawableobject))
			{
				player.setJumpHeight(JUMP_POWERUP_VALUE);
				hud.Update_jump(player.getJumpHeight());
				drawableobject->destroyed = true;
			}
			else if (std::shared_ptr<SpeedPowerup> speedpowerup = std::dynamic_pointer_cast<SpeedPowerup>(drawableobject))
			{
				player.setSpeed(SPEED_POWERUP_VALUE);
				hud.Update_speed(player.getSpeed());
				drawableobject->destroyed = true;
			}
			else if (std::shared_ptr<Floor> floor = std::dynamic_pointer_cast<Floor>(drawableobject))
			{
				hud.Update_lives();
				player.LoadCheckpoint(sf::Vector2f(CHECKPOINT_X, CHECKPOINT_Y));
			}
			else
			{
				player.OnCollision(direction);
			}
		}
	}

	for (auto& enemy : enemies)
	{
		Collider playerCollision = player.GetCollider();
		if (enemy->GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			hud.Update_lives();
			player.LoadCheckpoint(sf::Vector2f(CHECKPOINT_X, CHECKPOINT_Y));
		}
	}

	for (auto& drawableobject : drawableobjects)
	{
		for (auto& enemy : enemies)
		{
			Collider enemyCollision = enemy->GetCollider();
			if (std::shared_ptr<Platform> platform = std::dynamic_pointer_cast<Platform>(drawableobject))
			{
				if (drawableobject->GetCollider().CheckCollision(enemyCollision, direction, 1.0f))
				{
					enemy->OnCollision(direction);
				}
			}
		}
	}
}

void Game::DestroyObjects()
{
	int counter = 0;
	for (std::vector<std::shared_ptr<DrawableObjects>>::iterator it = drawableobjects.begin(); it != drawableobjects.end(); ++it)
	{
		if (drawableobjects[counter]->destroyed == true)
		{
			drawableobjects.erase(it);
			break;
		}
		counter++;
	}
}

void Game::ViewHandler()
{
	view.setCenter(player.GetPosition());
	window.clear();
	window.setView(view);
}

void Game::DrawObjects()
{
	background.Draw(window);

	player.Draw(window);

	for (auto& drawableobject : drawableobjects)
		drawableobject->Draw(window);

	for (auto& enemy : enemies)
		enemy->Draw(window);
}

void Game::HudViewHandler()
{
	window.setView(viewHud);
}

void Game::DrawHud()
{
	hud.Draw(window);
}

void Game::WindowDisplay()
{
	window.display();
}

void Game::EndGame(sf::Event event)
{
	if (hud.getLives() == 0 || hud.getScore() == coinAmount)
	{
		while (true)
		{
			window.clear(sf::Color::White);
			window.pollEvent(event);
			background.Draw(window);

			if (hud.getLives() == 0)
				hud.Update_lose(window);
			else if (hud.getScore() == coinAmount)
				hud.Update_win(window);

			if (event.type == sf::Event::Closed)
			{
				ExitGame();
				break;
			}
			else if (event.type == sf::Event::JoystickButtonPressed)
			{
				if (event.joystickButton.button == sf::Joystick::PovX ||
					event.joystickButton.button == sf::Joystick::PovY)
				{
					ExitGame();
					break;
				}
			}
			window.display();

			if (event.type == sf::Event::KeyPressed || 
				event.type == sf::Event::JoystickButtonPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					ExitGame();
					break;
				}
			}
		}
	}
}

void Game::ExitGame()
{
	window.close();
}
