#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}



void GameMenu::OutputOptions()  {
	Line(game->GetDescription()) ;
	Line(std::to_string(game->GetCost()));
	
	for (int i = 0; i < app->GetCurrentUser()->GetLibrary().length(); i++) {
		if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() != game)
		{
			Option('D', "Purchase");
		}
	}
}

bool GameMenu::HandleChoice(char choice) {
	switch (choice)
	{
	case 'D':
	{
		app->GetCurrentUser()->AddLibraryItem(game);
	} break;
	}
	return true;
}



//bool GameMenu::HandleChoice(char choice)
//{
//	//Handle buying here
//}
