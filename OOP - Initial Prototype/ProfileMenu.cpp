#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Utils util = Utils();
	Line("Credits: " + std::to_string(app->GetCurrentUser()->GetCredit()));
	Line("Games");
	for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
		Line(std::to_string(i + 1) + ") " + app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame()->GetName() + " Playtime: " + util.FormatPlaytime(app->GetCurrentUser()->GetLibrary()[i]->GetGameTime()));
	}
	Option('P', "Play Games");
	if (app->GetCurrentUser()->HasPermissions()) {
		Option('A', "Add User");
		Option('D', "Delete User");
	}
	
}

bool ProfileMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'A': {
		std::string tempusername = Question("Enter New Username");
		std::string temppassword = Question("Enter New Password");
		Date dt = Date().GetCurrentDate();
		Player* p1 = new Player(tempusername, temppassword, dt, 0);
		app->GetCurrentAccount()->addUser(p1);
	} break;
	case 'P': {
		int count = 0;
		for (int i = 0; i < app->GetCurrentUser()->GetLibrary().size(); i++) {
			count++;
			Utils util = Utils();
			Option(count, app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame()->GetName() + "	" + util.FormatPlaytime(app->GetCurrentUser()->GetLibrary()[i]->GetGameTime()));
		}
		while (true) {
			std::string gameChoice = Question("Select A Game");
			int int_2 = stoi(gameChoice);
			int_2--;
			if (int_2 <= app->GetCurrentUser()->GetLibrary().size()) {
				Utils util = Utils();
				app->GetCurrentUser()->GetLibrary()[int_2]->AddGameTime(util.getRandomPlayInt());
				break;
			}
			else if (gameChoice == "B" || gameChoice == "b") {
				break;
			}
		}

	}break;
	case 'D': {
		int count = 0;
		for (int i = 0; i < app->GetCurrentAccount()->getUsers().length(); i++) {
			count++;

			Option(count, app->GetCurrentAccount()->getUsers()[i]->GetUsername());
		}
		std::string accountChoice = Question("Select a User Account");
		int int_1 = stoi(accountChoice);
		int_1--;
		if (app->GetCurrentAccount()->getUsers()[int_1] == app->GetCurrentUser()) 
		{
			Line("test");
		}
		else 
		{
			while (true) 
			{
				std::string deleteItem = Question("Are you sure?");
				if (deleteItem == "Y" || deleteItem == "y") 
				{
					app->GetCurrentAccount()->DeleteUser(app->GetCurrentAccount()->getUsers()[int_1]);
					break;
				}
				else if (deleteItem == "N" || deleteItem == "n") {
					break;
				}
			}
		}


	} break;
	} return false;
	
}
