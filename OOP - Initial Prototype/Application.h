#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include <algorithm>
class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& password, int index);
		void LoginAccount(int i);
		void LogoutAccout();
		bool LoginUser(int i);
		void LogoutUser();
		bool LogIn(std::string& username, std::string& password);
		


		List <Account*> accounts;
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;

		std::string username;
		std::string password;
};