#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}

void GameMenu::DisplayGame() {

	Line(game->GetName());
	Line(game->GetDescription()) ;
	Line(std::to_string(game->GetCost()));
}

//bool GameMenu::HandleChoice(char choice)
//{
//	//Handle buying here
//}
