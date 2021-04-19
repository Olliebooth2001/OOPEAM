#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "LoginUserMenu.h"
#include "CreditMenu.h"
#include "ProfileMenu.h"

class MainMenu : public Menu
{
public:
	MainMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

};