#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}



void GameMenu::OutputOptions()  {
	Line(game->GetDescription()) ;
	Line(std::to_string(game->GetCost()));
}

bool GameMenu::HandleChoice(char choice) {
	return true;
}



//bool GameMenu::HandleChoice(char choice)
//{
//	//Handle buying here
//}
