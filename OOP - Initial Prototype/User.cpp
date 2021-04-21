#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created, int credit)
	: username(username), password(password), created(created), credit (credit)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string& User::GetPassword() const
{
	return password;
}

const int User::GetCredit() const
{
	return credit;
}

void User::AddCredit(int amount)
{
	credit = credit + amount;
}

bool User::EnoughCredit(int amount)
{
	if (credit >= amount) return true;

	return false;
}

void User::BuyGame(int amount)
{
	if (EnoughCredit(amount)) {
		credit = credit - amount;
	}

}

std::vector<LibraryItem*>& User::GetLibrary() {
	return std::vector<LibraryItem*>();
}

void User::AddLibraryItem(Date date, Game*& game) {
}

bool User::HasPermissions()
{
	return false;
}

const Date User::GetDate() const
{
	return created;
}

