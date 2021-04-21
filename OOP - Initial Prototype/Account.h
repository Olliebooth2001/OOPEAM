#pragma once

#include <string>
#include "Player.h"
#include "List.h"
#include "Date.h"

class Account
{
public:
	Account(const std::string&, const std::string&, const Date&);
	~Account();
	List <User*> getUsers();
	void addUser(User* user);
	void DeleteUser(User* user);

	std::string getEmail();
	std::string getPassword();
	Date getDateCreated();
	std::string getDateCreatedAsString();
private:
	List <User*> users;
	std::string email;
	std::string password;
	Date created;
};