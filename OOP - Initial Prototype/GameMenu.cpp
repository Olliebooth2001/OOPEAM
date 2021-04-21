#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}



void GameMenu::OutputOptions()  {
	bool flag = false;
	Line(game->GetDescription()) ;
	Line(std::to_string(game->GetCost()));
	
	for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
		if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() == game)
		{
			flag = true;
		}
	}
	if (flag == false) {
		Option('D', "Buy Game");
	}
}

bool GameMenu::HandleChoice(char choice) {
	switch (choice)
	{
	case 'D':
	{
		if (app->GetCurrentUser()->EnoughCredit(game->GetCost())) {
			app->GetCurrentUser()->BuyGame(game->GetCost());
			Date dt = Date();
			dt.GetCurrentDate();
			app->GetCurrentUser()->AddLibraryItem(dt, game);
		}
	} break;
	}
	return true;
}



//bool GameMenu::HandleChoice(char choice)
//{
//	//Handle buying here
//}
