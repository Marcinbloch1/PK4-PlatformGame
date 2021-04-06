#pragma once
#include <memory>
#include <cassert>

#define MENU_WINDOW_WIDTH 320
#define MENU_WINDOW_HEIGHT 320
#define NUMBER_MENU_ITEMS 3

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define VIEW_WIDTH 1280.0f
#define VIEW_HEIGHT 720.0f

#define SCORE_TEXT_X 620 
#define SCORE_TEXT_Y 340
#define LIVES_TEXT_X 620 
#define LIVES_TEXT_Y 310
#define JUMP_TEXT_X 620 
#define JUMP_TEXT_Y 280
#define SPEED_TEXT_X 620 
#define SPEED_TEXT_Y 250

#define PLAYER_SPEED 150.0f
#define PLAYER_JUMP_HEIGHT 200.0f

#define JUMPING_ENEMY_SPEED 20.0f
#define JUMPING_ENEMY_JUMP_HEIGHT 50.0f

#define FAST_ATTACK_ENEMY_SPEED 50.0f

#define MOVING_PLATFORM_SPEED 50.0f

#define LIVES 3
#define COIN_VALUE 1
#define HIT_VALUE 1

static const float PLAYER_SIZE_X = 30.0f;
static const float PLAYER_SIZE_Y = 50.0f;

static const float ENEMY1_SIZE_X = 30.0f;
static const float ENEMY1_SIZE_Y = 50.0f;

static const float ENEMY2_SIZE_X = 40.0f;
static const float ENEMY2_SIZE_Y = 50.0f;

static const float PLATFORM_SIZE_X = 250.0f;
static const float PLATFORM_SIZE_Y = 40.0f;

static const float COIN_SIZE_X = 40.0f;
static const float COIN_SIZE_Y = 40.0f;

static const float POWERUP_SIZE_X = 30.0f;
static const float POWERUP_SIZE_Y = 30.0f;

static const float LEVEL1_STARTING_POINT_X = 0.0f;
static const float LEVEL1_STARTING_POINT_Y = 700.0f;

static const float LEVEL2_STARTING_POINT_X = 0.0f;
static const float LEVEL2_STARTING_POINT_Y = 650.0f;

static const float LEVEL3_STARTING_POINT_X = 0.0f;
static const float LEVEL3_STARTING_POINT_Y = 2350.0f;

static float CHECKPOINT_X = 0.0f;
static float CHECKPOINT_Y = 0.0f;

static const float JUMP_POWERUP_VALUE = 50.0f;
static const float SPEED_POWERUP_VALUE = 50.0f;

static const int COIN_AMOUNT_LEVEL_1 = 7;


enum class TEXTURES
{
	PLAYER_TEXTURE,
	ENEMY_TEXTURE_1,
	ENEMY_TEXTURE_2,
	PLATFORM_TEXTURE,
	BACKGROUND_TEXTURE,
	COIN_TEXTURE,
	JUMPPOWERUP_TEXTURE,
	SPEEDPOWERUP_TEXTURE
};