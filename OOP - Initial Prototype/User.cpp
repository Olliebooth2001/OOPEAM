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

const Date User::GetDate() const
{
	return created;
}

