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
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 60);
    return dist6(rng);
}

std::string Utils::FormatPlaytime(float gametime)
{
    std::string str = "";
    if (gametime >= 60 && gametime < 300 )
    {   
        gametime = gametime / 60;
        str = std::to_string(gametime);
        return str.substr(0, 3) + " Hours";
    }
    else if (gametime >= 300)
    {
        gametime = gametime / 60;
        int hours = static_cast<int>(gametime);
        str = std::to_string(hours) + " hours";
        return str;
    }
    else {
        int minutes = static_cast<int>(gametime);
        str = std::to_string(minutes) + " Mins";
        return str;
    }
}

