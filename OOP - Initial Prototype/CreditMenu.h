#pragma once
#include "Menu.h"

class CreditMenu : public Menu
{
public:
	CreditMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
};

