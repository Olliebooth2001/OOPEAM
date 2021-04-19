#include "CreditMenu.h"

CreditMenu::CreditMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}

void CreditMenu::OutputOptions()
{
    Option(1, "10.00");
    Option(2, "20.00");
    Option(3, "30.00");
    Option(4, "40.00");
    Option(5, "50.00");
}

bool CreditMenu::HandleChoice(char choice)
{
    switch (choice) 
    {
    case '1':
    {
        app->GetCurrentUser()->AddCredit(10);
    } break;
    case '2':
    {
        app->GetCurrentUser()->AddCredit(20);
    } break;
    case '3':
    {
        app->GetCurrentUser()->AddCredit(30);
    } break;
    case '4':
    {
        app->GetCurrentUser()->AddCredit(40);
    } break;
    case '5':
    {
        app->GetCurrentUser()->AddCredit(50);
    } break;
    return false;
    }
}
