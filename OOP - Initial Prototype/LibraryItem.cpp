#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& purchased, Game* game, float playtime, bool hasRated)
	: purchased(purchased), game(game), playtime(playtime), hasRated(hasRated)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetLibraryGame() const
{
	return game;
}

int LibraryItem::GetGameTime() const
{
	return playtime;
}

void LibraryItem::AddGameTime(int time)
{
	playtime = playtime + time;
}

Date LibraryItem::getPurchaseDate() const
{
	return purchased;
}

void LibraryItem::setHasRated()
{
	hasRated = true;
}

bool LibraryItem::getHasRated()
{
	return hasRated;
}


