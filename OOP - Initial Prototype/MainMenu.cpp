#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	
	if(app->IsAccountLoggedIn())
	{
		if (app->IsUserLoggedIn())
		{
			Option('P', "View " + app->GetCurrentUser()->GetUsername() + "'s" + " Profile");
			Option('L', "Logout from " + app->GetCurrentUser()->GetUsername() + "'s Account");
		}
		else
		{
			Option('L', "Login User");
		}
	}
	else
	{
		if (app->IsAccountLoggedIn())
		{
			Option('A', "Logout Account");
		}
		else
		{
			Option('A', "Login Account");
		}
		
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
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			//BlockingMessage("Not implemented, press return to continue");
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	} break;
	case 'A':
	{
		if (app->IsAccountLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutAccout();
			}
		}
		else
		{
			//encapsulate
			int count = 0;
			for (int i = 0; i < app->accounts.length(); i++) 
			{
				count++;

				Option(count, app->accounts[i]->getEmail());
			}

			std::string selectedAccount = Question("Please select account");

			int int_1 = stoi(selectedAccount);
			int_1--;
			std::string username;

			while (true) {
				std::string tempPassword = Question("Please enter password");
				int tempUsername = int_1;

				if (app->LoginAccount(tempPassword, int_1)) 
				{
					app->LoginAccount(int_1);
					MainMenu("MAIN MENU", app);
					break;
				}
			}

		}

	}
	}

	return false;
}