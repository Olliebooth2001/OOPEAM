#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date& purchased, Game* game, float playtime, bool hasRated);
		~LibraryItem();
		const Game* GetLibraryGame() const;
		int GetGameTime() const;
		void AddGameTime(int time);
		Date getPurchaseDate() const;
		void setHasRated();
		bool getHasRated();
	private:
		const Game *game;
		const Date purchased;  
		float playtime;
		bool hasRated;

};