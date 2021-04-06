#include "SceneLoad.h"

SceneLoad::SceneLoad()
{
}

SceneLoad::~SceneLoad()
{
}

void SceneLoad::LoadLevel_1(std::vector<std::shared_ptr<DrawableObjects>>& drawableobjects, std::vector<std::shared_ptr<Enemy>>& enemies, Textures &texture)
{
	//Load drawables objects shared ptr
	//Load platforms
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 720.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(350.0f, 650.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(700.0f, 650.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2000.0f, 300.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2900.0f, 500.0f)));

	//Load moving platforms
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1100.0f, 650.0f), false, 300.0f, 650.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1700.0f, 300.0f), true, 1400.0f, 1700.0f));

	//Load floor
	drawableobjects.push_back(std::make_shared<Floor>(nullptr, sf::Vector2f(20000.0f, 1.0f), sf::Vector2f(-1000.0f, 4000.0f)));

	//Load coins
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(100.0f, 670.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2900.0f, 450.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(3000.0f, 450.0f)));

	//Load powerups
	drawableobjects.push_back(std::make_shared<JumpPowerup>(&texture.getTexture(TEXTURES::JUMPPOWERUP_TEXTURE), sf::Vector2f(1900.0f, 250.0f)));
	drawableobjects.push_back(std::make_shared<SpeedPowerup>(&texture.getTexture(TEXTURES::SPEEDPOWERUP_TEXTURE), sf::Vector2f(2000.0f, 250.0f)));

	//Load enemies
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(450.0f, 630.0f), 225.0f, 475.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(800.0f, 630.0f), 575.0f, 825.0f));
}

void SceneLoad::LoadLevel_2(std::vector<std::shared_ptr<DrawableObjects>>& drawableobjects, std::vector<std::shared_ptr<Enemy>>& enemies, Textures& texture)
{
	//Load platforms
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 700.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1000.0f, 300.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1900.0f, 600.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3800.0f, 600.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3700.0f, 2000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3300.0f, 2000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2800.0f, 2200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2400.0f, 2100.0f)));

	//Load moving platforms
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(500.0f, 600.0f), false, 300.0f, 600.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1500.0f, 300.0f), false, 300.0f, 600.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2300.0f, 600.0f), true, 2300.0f, 2700.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3400.0f, 600.0f), true, 3000.0f, 3400.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(4200.0f, 600.0f), false, 600.0f, 1000.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(4200.0f, 1500.0f), false, 1100.0f, 1500.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(4200.0f, 1600.0f), false, 1600.0f, 2000.0f));

	//Load coins
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(1000.0f, 260.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(4200.0f, 560.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2800.0f, 2160.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2400.0f, 2060.0f)));

	//Load floor
	drawableobjects.push_back(std::make_shared<Floor>(nullptr, sf::Vector2f(20000.0f, 0.1f), sf::Vector2f(-1000.0f, 10000.0f)));

	//Load enemies
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(1000.0f, 250.0f), 875.0f, 1125.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(1900.0f, 550.0f), 1775.0f, 2025.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(3800.0f, 550.0f), 3675.0f, 3925.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(3700.0f, 1950.0f), 3575.0f, 3825.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(3300.0f, 1950.0f), 3175.0f, 3425.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(2800.0f, 2150.0f), 2675.0f, 2925.0f));
}

void SceneLoad::LoadLevel_3(std::vector<std::shared_ptr<DrawableObjects>>& drawableobjects, std::vector<std::shared_ptr<Enemy>>& enemies, Textures& texture)
{
	//Load platforms
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 2400.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(850.0f, 2000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1300.0f, 1900.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(850.0f, 1800.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(-300.0f, 400.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 300.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(400.0f, -500.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(850.0f, -650.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1300.0f, -800.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1800.0f, -800.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2100.0f, -700.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3200.0f, -500.0f)));

	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(900.0f, 3800.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(900.0f, 4000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(900.0f, 4200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1650.0f, 4400.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2100.0f, 4200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2900.0f, 4200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3500.0f, 4000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(4400.0f, 4200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(5000.0f, 4000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(4400.0f, 3800.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3800.0f, 3600.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3200.0f, 3400.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3200.0f, 3200.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(3200.0f, 3000.0f)));
	drawableobjects.push_back(std::make_shared<Platform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2600.0f, 2800.0f)));

	//Load moving platforms
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(400.0f, 2000.0f), false, 2000.0f, 2300.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(350.0f, 1750.0f), true, 0.0f, 350.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 1600.0f), false, 1300.0f, 1600.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 900.0f), false, 900.0f, 1200.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 800.0f), false, 500.0f, 800.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(600.0f, 300.0f), true, 600.0f, 1000.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1400.0f, 300.0f), false, 0.0f, 300.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(1000.0f, 0.0f), true, 700.0f, 1000.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, 0.0f), true, 0.0f, 400.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(0.0f, -150.0f), false, -500.0f, -150.0f));
	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(2400.0f, -500.0f), true, 2400.0f, 2800.0f));

	drawableobjects.push_back(std::make_shared<MovingPlatform>(&texture.getTexture(TEXTURES::PLATFORM_TEXTURE), sf::Vector2f(400.0f, 4000.0f), false, 2600.0f, 4000.0f));

	//Load coins
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(-100.0f, 2360.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(450.0f, 600.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(500.0f, 800.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(550.0f, 1000.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(600.0f, 1200.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(650.0f, 1400.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(1300.0f, 1760.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(1300.0f, 1860.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(0.0f, 260.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(400.0f, -540.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(1300.0f, -840.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2100.0f, -740.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(1650.0f, 4360.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2900.0f, 4160.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(3500.0f, 3960.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(4400.0f, 3760.0f)));
	drawableobjects.push_back(std::make_shared<Coin>(&texture.getTexture(TEXTURES::COIN_TEXTURE), sf::Vector2f(2600.0f, 2760.0f)));


	//Load powerups
	drawableobjects.push_back(std::make_shared<JumpPowerup>(&texture.getTexture(TEXTURES::JUMPPOWERUP_TEXTURE), sf::Vector2f(3200.0f, -540.0f)));
	drawableobjects.push_back(std::make_shared<SpeedPowerup>(&texture.getTexture(TEXTURES::SPEEDPOWERUP_TEXTURE), sf::Vector2f(2100.0f, 4160.0f)));

	//Load floor
	drawableobjects.push_back(std::make_shared<Floor>(nullptr, sf::Vector2f(20000.0f, 0.1f), sf::Vector2f(-1000.0f, 10000.0f)));

	//Load enemies
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(500.0f, 1900.0f), 275.0f, 525.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(1400.0f, -950.0f), 1175.0f, 1425.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(1900.0f, -950.0f), 1675.0f, 1925.0f));

	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(1000.0f, 3750.0f), 775.0f, 1025.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(820.0f, 3950.0f), 775.0f, 1025.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(820.0f, 4150.0f), 775.0f, 1025.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(3000.0f, 4150.0f), 2775.0f, 3025.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(3600.0f, 3950.0f), 3375.0f, 3625.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(5100.0f, 3950.0f), 4875.0f, 5125.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(3300.0f, 3350.0f), 3075.0f, 3325.0f));
	enemies.push_back(std::make_shared<FastAttackEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_2), sf::Vector2u(3, 3), 0.3f, sf::Vector2f(3300.0f, 3150.0f), 3075.0f, 3325.0f));
	enemies.push_back(std::make_shared<JumpingEnemy>(&texture.getTexture(TEXTURES::ENEMY_TEXTURE_1), sf::Vector2u(4, 4), 0.3f, sf::Vector2f(3300.0f, 2950.0f), 3075.0f, 3325.0f));
}
