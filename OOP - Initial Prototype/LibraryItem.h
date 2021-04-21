#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*, float playtime);
		~LibraryItem();
		const Game* GetLibraryGame();
		int GetGameTime();
		void AddGameTime(int time);
	private:
		const Game *game;
		const Date purchased;  
		float playtime;

};