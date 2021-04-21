#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, int credit)
	: User(username, password, created, credit)
{
}

Player::~Player()
{
	for (int i = 0; i < library.size(); ++i)
	{
		delete library[i];
	}
}

std::vector<LibraryItem*>& Player::GetLibrary()
{
	return library;
}

void Player::AddLibraryItem(Date date,Game*& game)
{
	library.push_back(new LibraryItem(date, game, 0));
}