#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, int);
		~Player();
		List<LibraryItem*>& GetLibrary() override;
		void AddLibraryItem(Date date, Game*& game) override;
		List<LibraryItem*> library; 
		
	private:

};