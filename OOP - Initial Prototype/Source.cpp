 #include <iostream>
#include <string>
#include "Application.h"
#include "MainMenu.h"
#include "fileHandler.h"

void main()
{

	Application app;
	fileHandler handler;
	

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
	
	

	//TODO: Recursion
	//TODO: Tidy up Loops to use auto.
}