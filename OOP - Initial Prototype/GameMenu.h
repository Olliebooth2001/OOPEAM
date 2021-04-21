#pragma once

#include "Menu.h"

#include <string>


class GameMenu : public Menu
{
public:
	GameMenu(const std::string& title, Application* app, Game* game);

	void OutputOptions() final override;

	bool HandleChoice(char choice) final override;
	
private:

	Game* game;

};