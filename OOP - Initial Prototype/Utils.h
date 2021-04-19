#pragma once

#include <string>
#include <iostream>
#include "List.h"
#include "Game.h"

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();

    List<Game> ReadFromFile(const std::string& directory);
    void savefile();


    // TODO: 2 versions of ToUpper
};