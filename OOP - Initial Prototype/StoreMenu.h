#pragma once

#include "Menu.h"

#include <string>
#include <vector>

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app, List<Game*> games);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	List<Game*> getGames();
	void addGame(Game* games);
private:
	List<Game*> games;

};