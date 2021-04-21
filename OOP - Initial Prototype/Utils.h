#pragma once

#include <string>
#include <iostream>
#include "List.h"
#include "Game.h"
#include "Player.h"
#include "Account.h"
#include "Admin.h"
#include "LibraryItem.h"
#include "Application.h"

class Utils
{
private:
    Date parseDate(const std::string& stringDate);

  public:
    static std::string getLineFromUser();
    static char getCharFromUser();

    List<Game> ReadGameDataFromFile(const std::string& directory);
    List<Account*> ProcessFileData(Application& app, const std::string& dir);

    void savefile();


    // TODO: 2 versions of ToUpper
};