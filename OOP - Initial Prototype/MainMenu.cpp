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
			Option('C', "Buy Credit");
			Option('F', "Search Store");
			Option('L', "Logout from " + app->GetCurrentUser()->GetUsername() + "'s Account");
		}
		else
		{
			Option('L', "Login User");
			Option('A', "Logout Account");
		}
	}
	else
	{
		
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
			
			if (app->IsAccountLoggedIn())
			{
				LoginUserMenu("LOGIN USER MENU", app);
			}
		
			
			
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
			ProfileMenu(app->GetCurrentUser()->GetUsername(), app);
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
			for (int i = 0; i < app->GetAccounts().length(); i++)
			{
				count++;

				Option(count, app->GetAccounts()[i]->getEmail());
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
	case 'C':
	{
		if (app->IsUserLoggedIn()) {
			CreditMenu("Credit", app);
		}
	}break;
	}

	return false;
}

