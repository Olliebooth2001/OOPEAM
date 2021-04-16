#include "StoreMenu.h"


StoreMenu::StoreMenu(const std::string& title, Application* app, List<Game*> games) : Menu(title, app), games(games)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	
	for (int i = 0; i < games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]->GetName());
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < games.length())
	{

	  GameMenu(games[index]->GetName(), app, app->GetStore().getGames()[index]).OutputOptions();

	  //ollie go poopoo
	  
		// go to game detail page
	}

	return false;
}
 
List<Game*> StoreMenu::getGames() 
{

	return games;

}
void StoreMenu::addGame(Game* games) 
{



}