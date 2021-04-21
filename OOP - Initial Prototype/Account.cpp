#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		delete users[i];
	}
}

List <User*> Account::getUsers() 
{
	return users;
}
void Account::addUser(User* user)
{
	users.addAtEnd(user);
}

void Account::DeleteUser(User* user)
{
	users.deleteOne(user);
}

std::string Account::getEmail()
{
	return email;
}

std::string Account::getPassword()
{
	return password;
}

Date Account::getDateCreated()
{
	return created;
}

std::string Account::getDateCreatedAsString()
{
	return created.GetDate();
}