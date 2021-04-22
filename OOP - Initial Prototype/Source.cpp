 #include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "Date.h"
#include "MainMenu.h"
#include "fileHandler.h"

// TODO: Remove from global scope once menu system is integrated
Application app;
fileHandler handler;


//char showMainMenuAndGetUserChoice()
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= GAME LIBRARY =-\n";
//	std::cout << "                    \n";
//	std::cout << "  S) Browse Store   \n";
//
//	if (app.IsUserLoggedIn())
//	{
//		std::cout << "  L) Logout of " << app.GetCurrentUser()->GetUsername() << "\n";
//		// TODO: User profile option
//	}
//	else
//	{
//		std::cout << "  L) Login      \n";
//	}
//
//	std::cout << "                    \n";
//	std::cout << "  B) Exit           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::getCharFromUser();
//}
//
//char showStoreMenuAndGetUserChoice()
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= STORE =-       \n";
//	std::cout << "                    \n";
//
//	// Output game list
//	for (int i = 0; i < app.GetStore().getGames().length()-1; i++)
//	{
//		
//		std::cout << "  " << (i + 1) << ") " << app.GetStore().getGames()[i]->GetName() << "\n";
//	}
//
//	// Output rest of menu
//	std::cout << "                    \n";
//	std::cout << "  B) Back           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::getCharFromUser();
//}
//
//char showLoginUserMenuAndGetUserChoice(Account *account)
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= LOGIN =-       \n";
//	std::cout << "                    \n";
//
//	// Output user list
//	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
//	{
//		std::cout << "  " << (i + 1) << ") " << account->getUsers()[i]->GetUsername() << "\n";
//	}
//
//	// Output rest of menu
//	std::cout << "                    \n";
//	std::cout << "  B) Back           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::getCharFromUser();
//}
//
//char showGameMenuAndGetUserChoice(Game* game)
//{
//	system("CLS");
//	std::cout << "                                  \n";
//	std::cout << "  -= " << game->GetName() << " =- \n";
//	std::cout << "                                  \n";
//	std::cout << "  " << game->GetDescription() << "\n";
//	std::cout << "                                  \n";
//
//	if (app.IsUserLoggedIn())
//	{
//		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
//		std::cout << "                                                      \n";
//	}
//
//	std::cout << "  B) Back                   \n";
//	std::cout << "                            \n";
//	std::cout << "                            \n";
//	std::cout << "  >>> ";
//
//	return Utils::getCharFromUser();
//}
//
//void gameMenu(Game* game)
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showGameMenuAndGetUserChoice(game);
//
//		switch (choice)
//		{
//			case 'P': {
//				if (app.IsUserLoggedIn())
//				{
//					// TODO: Implement buying from the store
//				}
//			} break;
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//		}
//	}
//}
//
//void storeMenu()
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showStoreMenuAndGetUserChoice();
//
//		switch (choice)
//		{
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//			default: {
//				int index = choice - '1';
//
//				if (index >= 0 && index < 9) // TODO: Hardcoded numbers, change when using List<T>
//				{
//					gameMenu(app.GetStore().getGames()[index]);
//				}
//			} break;
//		}
//	}
//}
//
//void loginUserMenu()
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showLoginUserMenuAndGetUserChoice(app.GetCurrentAccount());
//
//		switch (choice)
//		{
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//			default: {
//				int index = choice - '1';
//
//				if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
//				{
//					std::string username = app.GetCurrentAccount()->getUsers()[index]->GetUsername();
//
//					std::cout << "  Enter password for " << username << ": ";
//					/*if (app.LoginUser(username, Utils::getLineFromUser()))
//					{
//						readyToGoBack = true;
//					}*/
//				}
//			} break;
//		}
//	}
//}
//
//void mainMenu()
//{
//	bool wantsToExit = false;
//
//	while (wantsToExit == false)
//	{
//		int choice = showMainMenuAndGetUserChoice();
//
//		switch (choice)
//		{
//			case 'S': {
//				storeMenu();
//			} break;
//			case 'L': {
//				if (app.IsUserLoggedIn())
//				{
//					app.LogoutUser();
//				}
//				else
//				{
//					loginUserMenu();
//				}
//			} break;
//			case 'B': {
//				wantsToExit = true;
//			} break;
//		}
//	}
//}

void main()
{
	

	List<Game> GameData = handler.ReadGameDataFromFile("Data.txt");

	for (int i = 0; i < GameData.length(); i++)
	{
		app.GetStore().getGames().addAtEnd(new Game
		(
			GameData[i].GetName(),
			GameData[i].GetDescription(),
			GameData[i].GetCost(),
			GameData[i].GetRating(),
			GameData[i].GetID())
		);
	}

	List<Account*> accounts = handler.ProcessFileData(app, "Data.txt");

	for (int i = 0; i < accounts.length(); i++)
	{
		app.accounts.addAtEnd(accounts[i]);
	}
	

	
	MainMenu("MAIN MENU", &app);

	handler.saveToFile(app, "Data.txt");
	

	// TODO: app.Save();
	

	//TODO: Recursion
	//TODO: Tidy up Loops to use auto.
}