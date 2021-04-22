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
#include <random>
#include <string>

//#include "Application.h"

class Utils
{
private:
    int randomint;
    std::string input;
    std::string fullText;
    std::string searchText;
    

  public:
    static std::string getLineFromUser();
    static char getCharFromUser();

    
    static bool StartsWith(std::string fullText, std::string searchText);

    int getRandomPlayInt();

    std::string FormatPlaytime(float gametime);


    static std::string ToUpper(std::string input);
    static std::string ToUpperRecursive(std::string input);
    

};