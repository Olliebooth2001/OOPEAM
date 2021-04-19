#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View " + app->GetCurrentUser()->GetUsername() +"'s"+" Profile");
		Option('C', "Buy Credit");
		Option('F', "Search Store");
		Option('L', "Logout from " + app->GetCurrentUser()->GetUsername()+"'s Account");
	}
	else
	{
		Option('L', "Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app, app->GetStore().getGames());
		
	} break;
	case 'L':
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();
			}
		}
		else
		{
			
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
		
			LoginUserMenu("LOGIN USER MENU",app);
			
		}
	} break;
	case 'F':
	{
		system("CLS");


		Line("To search for a title press T, to select a price range press P");
		Option('T', "Title");
		Option('P', "Price Range");
		std::string answer = Question("Select");

		if (answer == "T" || answer == "t") {
			std::string ans2 = Question("Enter Title Name");
			StoreMenu("STORE", app, app->GetStore().searchByName(ans2));
		}
		else if (answer == "P" || answer == "p")
		{

			Option('1', "0-1000");
			Option('2', "1000-2000");
			Option('3', "Over 2000");
			std::string ans = Question("Select Price Range");

			int iResponse = stoi(ans);
			StoreMenu("STORE", app, app->GetStore().searchByPriceRange(iResponse));
		}
	} break;

	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			//BlockingMessage("Not implemented, press return to continue");
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	} break;

	case 'C':
	{
		if (app->IsUserLoggedIn())
		{
			CreditMenu("Credit", app);
		}
	} break;
	}

	return false;
}

