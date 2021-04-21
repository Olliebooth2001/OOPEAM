#pragma once

#include <string>
#include <iostream>
#include "List.h"
#include "Game.h"
#include "Player.h"
#include "Account.h"
#include "Admin.h"
#include "LibraryItem.h"
#include <algorithm> 

//#include "Application.h"

class Utils
{
private:
    

  public:
    static std::string getLineFromUser();
    static char getCharFromUser();

    
    static bool StartsWith(std::string fullText, std::string searchText);



    // TODO: 2 versions of ToUpper
    static std::string ToUpper(std::string input);
    static std::string ToUpperRecursive(std::string input);

    std::string input;
    std::string fullText;
    std::string searchText;

};