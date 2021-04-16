#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*>& getGames();
	private:
		List<Game*> games;
};