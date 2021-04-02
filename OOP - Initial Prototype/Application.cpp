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
	
	bool passFlag;
	bool userFlag;
	for (int i = 0; i < accounts.length(); i++) 
	{
		for (int a = 0; a < accounts[i]->item->users.length(); a++) 
		{
			if (accounts[i]->item->users[a]->item->GetUsername() == username) {
				userFlag = true;
			}
		}
		for (int a = 0; a < accounts[i]->item->users.length(); a++)
		{
			if (accounts[i]->item->users[a]->item->GetPassword() == password) {
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
	currentAccount = accounts[0]->item;

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users[0]->item;

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}