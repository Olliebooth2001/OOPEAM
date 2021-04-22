#include "GameMenu.h"

GameMenu::GameMenu(const std::string& title, Application* app, Game* game) : Menu(title, app), game(game)
{
	Paint(); // required in constructor
}



void GameMenu::OutputOptions()  {
	if (app->IsUserLoggedIn()) {
		bool flag = false;
		bool flag2 = false;
		Line(game->GetDescription());
		Line(std::to_string(game->GetCost()));
		if (game->GetRating() == 0) { Line("Rating: not yet rated!"); }
		else { Line("Rating: " + std::to_string(game->GetRating()) + "%"); }
		

		for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
			if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() == game)
			{
				flag = true;
			}
		}
		if (flag == false) {
			Option('D', "Buy Game");
		}
		for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) 
		{
			if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() == game && !app->GetCurrentUser()->GetLibrary()[i]->getHasRated())
			{
				flag2 = true;
				
			}
		}
		if (flag2 == true)
		{
			Option('L', "Like Game");
			Option('N', "Dislike Game");
		}
	}
	else {
		bool flag = false;
		Line(game->GetDescription());
		Line(std::to_string(game->GetCost()));

	}

}

bool GameMenu::HandleChoice(char choice) {
	switch (choice)
	{
	case 'D':
	{
		if (app->GetCurrentUser()->EnoughCredit(game->GetCost())) {
			app->GetCurrentUser()->BuyGame(game->GetCost());
			Date dt = Date().GetCurrentDate();
			//dt.GetCurrentDate();
			app->GetCurrentUser()->AddLibraryItem(dt, game);
		}
	} break;
	case 'L':
	{
		game->addLike();
		for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
			if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() == game)
			{
				app->GetCurrentUser()->GetLibrary()[i]->setHasRated();
			}
		}


	} break;
	case 'N':
	{
		game->addDislike();
		for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
			if (app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame() == game)
			{
				app->GetCurrentUser()->GetLibrary()[i]->setHasRated();
			}
		}
	
	}
	}
	return true;
}



//bool GameMenu::HandleChoice(char choice)
//{
//	//Handle buying here
//}
