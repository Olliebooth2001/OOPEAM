#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&, int);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const int& GetCredit() const;
	private:
		std::string username;
		std::string password;
		Date created;  
		int credit;
};