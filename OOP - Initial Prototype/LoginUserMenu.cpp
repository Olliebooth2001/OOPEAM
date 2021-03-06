#include "LoginUserMenu.h"


LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}




void LoginUserMenu::OutputOptions()
{
	int count = 0;
	for (int i = 0; i < app->GetCurrentAccount()->getUsers().length(); i++) {
		count++;

		Option(count, app->GetCurrentAccount()->getUsers()[i]->GetUsername());
	}

	std::string selectedUser = Question("Please select user");

	try {
		int int_1 = stoi(selectedUser);
		int_1--;
		if (int_1 <= app->GetCurrentAccount()->getUsers().length()) {
			std::string username;
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			while (true) {
				std::string tempPassword = Question("Please enter password");
				std::string tempUsername = app->GetCurrentAccount()->getUsers()[int_1]->GetUsername();

				if (tempPassword == "B") {
					break;
				}
				if (app->LogIn(tempUsername, tempPassword)) {
					app->LoginUser(int_1);
					MainMenu("MAIN MENU", app);
					break;
				}
			}
		}
		else {
			Line("Error on Input");
		}
	}
	catch (std::exception e) {
		Line("Error on Input");
	}

}

bool LoginUserMenu::HandleChoice(char choice)
{
	return false;
}

