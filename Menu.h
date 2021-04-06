#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Background.h"
#include "Textures.h"
#include <iostream>

class Menu
{
private:
	sf::RenderWindow window;
	sf::Font font;
	sf::Text MenuText[NUMBER_MENU_ITEMS];
	sf::Event event;
	Textures texture;
	Background background;
	int selectedItem;
	int selectedLevel;
	bool isChosen;

public:
	Menu();
	~Menu();

	void MenuLoop();
	int GetLevel();

private:
	void EventHandler();
	void MoveUp();
	void MoveDown();
	void Draw();
	void WindowDisplay();
	void WindowClear();
	void CheckCloseMenu();
};