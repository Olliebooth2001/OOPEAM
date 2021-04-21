#pragma once
#include "List.h"
#include "Game.h"
#include "Date.h"
#include "Account.h"
#include "Application.h"
#include "Admin.h"

class fileHandler
{
public:
    List<Game> ReadGameDataFromFile(const std::string& dir);
    List<Account*> ProcessFileData(Application& app, const std::string& dir);

    void saveToFile(Application& app, const std::string& dir);

private:
    Date parseDate(const std::string& stringDate);

};

