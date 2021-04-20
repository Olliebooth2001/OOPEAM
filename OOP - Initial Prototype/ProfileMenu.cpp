#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Line("Credits: " + std::to_string(app->GetCurrentUser()->GetCredit()));
	Line("Games");
	for (int i = 0; i < app->GetCurrentUser()->GetLibrary().length(); i++) {
		Line(i + " " + app->GetCurrentUser()->GetLibrary()[i]->GetLibraryGame()->GetName());
	}
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
		Date dt = Date();
		dt.GetCurrentDate();
		Player* p1 = new Player(tempusername, temppassword, dt, 0);
		app->GetCurrentAccount()->addUser(p1);
		Line("Test");
	} break;
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
