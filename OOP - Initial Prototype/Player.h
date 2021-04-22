#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, int);
		~Player();
		std::vector<LibraryItem*>& GetLibrary() override;
		void AddLibraryItem(Date date, Game*& game) override;
		void AddToLibrary(LibraryItem* item) override;
		
	private:
		std::vector<LibraryItem*> library;
};