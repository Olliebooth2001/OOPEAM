#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

bool Utils::StartsWith(std::string fullText, std::string searchText) {

    int letters = searchText.length();

    std::string newString = fullText.substr(0, letters);

    if (std::tolower(newString == searchText)) {
        return true;
    }
    else {
        return false;
    }

}

int Utils::getRandomPlayInt()
{
    int randnum;
    return randnum = 1+ (rand() % 60);
}

void Utils::openfile()
{
}

void Utils::savefile()
{
}
