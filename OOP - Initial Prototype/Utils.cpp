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
std::string Utils::ToUpper(std::string input) {
    if (input.length() == 0) return "";
    transform(input.begin(), input.end(), input.begin(), toupper);
    return input;
}

std::string Utils::ToUpperRecursive(std::string input) {
    if (input.length() == 0) return "";
    return (char)toupper(input[0]) + ToUpper(input.substr(1));
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
//void Utils::openfile()
//{
//}


