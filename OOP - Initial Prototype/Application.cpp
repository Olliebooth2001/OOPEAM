#include "Application.h"


Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}
bool Application::LogIn(std::string& username, std::string& password) {
	
	bool passFlag = false;
	bool userFlag = false;


	for (int i = 0; i < accounts.length(); i++) 
	{
		for (int a = 0; a < accounts[i]->getUsers().length(); a++) 
		{
			if (accounts[i]->getUsers()[a]->GetUsername() == username) {
				userFlag = true;
			}
		}
		for (int a = 0; a < accounts[i]->getUsers().length(); a++)
		{
			if (accounts[i]->getUsers()[a]->GetPassword() == password) {
				passFlag = true;
			}
		}

	}
	if (passFlag == true && userFlag == true) {
		return true;
	}
	else {
		return false;
	}

}


bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

void Application::LoginAccount(int i)
{
	currentAccount = accounts[i];
}

bool Application::LoginAccount(const std::string& password, int index)
{
	
	if (accounts[index]->getPassword() == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Application::LoginUser(int i)
{
	if (currentUser = currentAccount->getUsers()[i])
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogoutAccout()
{
	currentAccount = nullptr;
}

List<Account*>  Application::GetAccounts()
{
	return accounts;
}

void Application::addAccount(Account* acc)
{
	accounts.addAtEnd(acc);
}