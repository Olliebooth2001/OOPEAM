#pragma once

#include "Menu.h"

#include <string>


class GameMenu : public Menu
{
public:
	GameMenu(const std::string& title, Application* app, Game* game);

	void DisplayGame() ;
	/*bool HandleChoice(char choice) final;*/
	
private:
	
	Game* game;

};