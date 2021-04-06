//#include <vld.h>
#include <stdexcept>
#include <iostream>
#include "Game.h"
#include "Menu.h"

int main()
{
	try
	{
		Menu menu;
		menu.MenuLoop();

		Game game(menu.GetLevel());
		game.GameLoop();
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Runtime error: " << e.what() << std::endl;
	}
	
	return 0;
}