#pragma once

#include <string>
#include "Date.h"
#include "List.h"
#include "LibraryItem.h"
#include <vector>

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
		virtual std::vector<LibraryItem*>& GetLibrary();
		virtual void AddToLibrary(LibraryItem* lib);
		virtual void AddLibraryItem(Date dt, Game*& game);
		virtual bool HasPermissions();
		Date GetDate() const;
		const std::string getDateAsString() const;

	private:
		std::string username;
		std::string password;
		Date created;  
		int credit;
};