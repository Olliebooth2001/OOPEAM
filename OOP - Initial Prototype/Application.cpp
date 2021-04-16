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

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(int i)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->getUsers()[i];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}