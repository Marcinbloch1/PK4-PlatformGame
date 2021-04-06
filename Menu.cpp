#include "Menu.h"

Menu::Menu() :
	window(sf::VideoMode(MENU_WINDOW_WIDTH, MENU_WINDOW_HEIGHT), "Menu"),
	selectedItem(0), selectedLevel(0), isChosen(false),
	background(texture.getTexture(TEXTURES::BACKGROUND_TEXTURE))
{
	window.setFramerateLimit(30);

	font.loadFromFile("Fonts/CaviarDreams.ttf");

	MenuText[0].setFont(font);
	MenuText[0].setString("Level 1 - Tutorial");
	MenuText[0].setCharacterSize(24);
	MenuText[0].setFillColor(sf::Color::Red);
	MenuText[0].setOrigin(MenuText[0].getLocalBounds().width / 2, MenuText[0].getLocalBounds().height / 2);
	MenuText[0].setPosition(window.getSize().x / 2.0f, (float)window.getSize().y / (NUMBER_MENU_ITEMS + 1) * 1);

	MenuText[1].setFont(font);
	MenuText[1].setString("Level 2 - Easy");
	MenuText[1].setCharacterSize(24);
	MenuText[1].setFillColor(sf::Color::Black);
	MenuText[1].setOrigin(MenuText[1].getLocalBounds().width / 2, MenuText[1].getLocalBounds().height / 2);
	MenuText[1].setPosition(window.getSize().x / 2.0f, (float)window.getSize().y / (NUMBER_MENU_ITEMS + 1) * 2);

	MenuText[2].setFont(font);
	MenuText[2].setString("Level 3 - Hard");
	MenuText[2].setCharacterSize(24);
	MenuText[2].setFillColor(sf::Color::Black);
	MenuText[2].setOrigin(MenuText[2].getLocalBounds().width / 2, MenuText[2].getLocalBounds().height / 2);
	MenuText[2].setPosition(window.getSize().x / 2.0f, (float)window.getSize().y / (NUMBER_MENU_ITEMS + 1) * 3);
}

Menu::~Menu()
{
}

void Menu::MenuLoop()
{
	while (window.isOpen())
	{
		EventHandler();
		Draw();
		WindowDisplay();
		WindowClear();
		CheckCloseMenu();
	}
}

void Menu::EventHandler()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		else if (event.type == sf::Event::KeyReleased ||
			event.type == sf::Event::JoystickButtonReleased)
		{
			if (event.key.code == sf::Keyboard::Up ||
				event.joystickButton.button == sf::Joystick::U)
			{
				MoveUp();
				break;
			}
			else if (event.key.code == sf::Keyboard::Down ||
				event.joystickButton.button == sf::Joystick::V)
			{
				MoveDown();
				break;
			}
			else if (event.joystickButton.button == sf::Joystick::PovX ||
				event.joystickButton.button == sf::Joystick::PovY)
			{
				window.close();
				break;
			}
			else if (event.key.code == sf::Keyboard::Enter || 
				event.joystickButton.button == sf::Joystick::X)
			{
				selectedLevel = selectedItem+1;
				isChosen = true;
				break; 
			}
		}
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		MenuText[selectedItem].setFillColor(sf::Color::Black);
		selectedItem--;
		MenuText[selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < NUMBER_MENU_ITEMS)
	{
		MenuText[selectedItem].setFillColor(sf::Color::Black);
		selectedItem++;
		MenuText[selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::Draw()
{
	background.Draw(window);
	for (int i = 0; i < NUMBER_MENU_ITEMS; i++)
	{
		window.draw(MenuText[i]);
	}
}

void Menu::WindowDisplay()
{
	window.display();
}

void Menu::WindowClear()
{
	window.clear(sf::Color(255, 255, 255));
}

void Menu::CheckCloseMenu()
{
	if (isChosen == true)
	{
		window.close();
	}
}

int Menu::GetLevel()
{
	return selectedLevel;
}
