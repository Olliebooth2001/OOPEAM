#include "CreditMenu.h"

CreditMenu::CreditMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}

void CreditMenu::OutputOptions()
{
    Option(1, "500");
    Option(2, "1000");
    Option(3, "2000");
    Option(4, "3000");
    Option(5, "4000");
}

bool CreditMenu::HandleChoice(char choice)
{
    switch (choice) 
    {
    case '1':
    {
        app->GetCurrentUser()->AddCredit(500);
    } break;
    case '2':
    {
        app->GetCurrentUser()->AddCredit(1000);
    } break;
    case '3':
    {
        app->GetCurrentUser()->AddCredit(2000);
    } break;
    case '4':
    {
        app->GetCurrentUser()->AddCredit(3000);
    } break;
    case '5':
    {
        app->GetCurrentUser()->AddCredit(4000);
    } break;
    return false;
    }
}
