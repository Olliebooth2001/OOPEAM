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
	
}

bool ProfileMenu::HandleChoice(char choice)
{
	return false;
}
