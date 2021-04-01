#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		//Game* games[9] = { }; // TODO: should be a dynamic collection
		List<Game*> games;

	private:
};