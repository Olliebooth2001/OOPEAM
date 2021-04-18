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
		const int GetCredit() const;
		void AddCredit(int amount);
		bool EnoughCredit(int amount);
		void BuyGame(int amount);

	private:
		std::string username;
		std::string password;
		Date created;  
		int credit;
};