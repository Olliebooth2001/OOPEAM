#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& purchased, Game* game)
	: purchased(purchased), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetLibraryGame()
{
	return game;
}

int LibraryItem::GetGameTime()
{
	// TODO: get GameTime of a game object, and change display depending on the value;
	return 0;
}

void LibraryItem::AddGameTime(int time)
{
	//TODO: Increment Game Time by set amount 
	//gameTime + 30; or smthn
}


