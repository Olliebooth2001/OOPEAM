#include "LoginUserMenu.h"


LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}




void LoginUserMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout");
	}
	else
	{
		Option('L', "Login");
	}
}

bool LoginUserMenu::HandleChoice(char choice)
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
			//encapsulate
			int count = 0;
			for (int i = 0; i < app->GetCurrentAccount()->getUsers().length(); i++) {
				count++;

				Option(count,  app->GetCurrentAccount()->getUsers()[i]->GetUsername());
			}
			
			std::string selectedUser	= Question("Please select user");

			int int_1= stoi(selectedUser);
			int_1 --;
			std::string username;
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			while (true) {
				std::string tempPassword = Question("Please enter password");
				std::string tempUsername = app->GetCurrentAccount()->getUsers()[int_1]->GetUsername();

				if (app->LogIn(tempUsername,tempPassword)) {
					app->LoginUser(int_1);
					MainMenu("MAIN MENU", app);
					break;
				}
			}

		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{


			BlockingMessage("Not implemented, press return to continue");
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
		}
	} break;
	}

	return false;
}

