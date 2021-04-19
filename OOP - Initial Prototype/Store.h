#pragma once

#include "Game.h"
#include "List.h"
#include "Utils.h"
class Store
{
	public:
		Store();
		~Store();

		List<Game*> searchByPriceRange(int priceRange);
		List<Game*>& getResults();
		List<Game*> searchByName(std::string inputString);

		List<Game*>& getGames();
		void addGame(Game* games);

	private:
		List<Game*> games;
		List<Game*> results;
		std::string inputString;
		int priceRange;
};