#pragma once
#include "Menu.h"
#include <string>
#include "User.h"

class ProfileMenu : public Menu
{
public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:

};

