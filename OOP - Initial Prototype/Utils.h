#pragma once

#include <string>
#include <iostream>
#include <random>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
    void openfile();
    void savefile();
    static bool StartsWith(std::string fullText, std::string searchText);
    int getRandomPlayInt();

    // TODO: 2 versions of ToUpper
    std::string fullText;
    std::string searchText;

};