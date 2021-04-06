#pragma once
#include "Definitions.h"
#include <memory>
#include <vector>
#include "Game.h"

class SceneLoad
{
public:
	SceneLoad();
	~SceneLoad();

	void LoadLevel_1(std::vector<std::shared_ptr<DrawableObjects>> &drawableobjects, std::vector<std::shared_ptr<Enemy>> &enemies, Textures &texture);
	void LoadLevel_2(std::vector<std::shared_ptr<DrawableObjects>> &drawableobjects, std::vector<std::shared_ptr<Enemy>> &enemies, Textures &texture);
	void LoadLevel_3(std::vector<std::shared_ptr<DrawableObjects>>& drawableobjects, std::vector<std::shared_ptr<Enemy>>& enemies, Textures& texture);
};

