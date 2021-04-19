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


