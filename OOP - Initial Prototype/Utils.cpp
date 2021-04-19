#include "Utils.h"

#include <fstream>

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

List<Game> Utils::ReadFromFile(const std::string& directory)
{
    // declare/initialise variables.
    int lineCounter = 0;
    std::string line;
    List<Game> games;

    // open file.
    std::ifstream file(directory, std::ios_base::app);

    // tmp buffer variables.
    int id = 0;
    std::string name = "";
    std::string desc = "";
    int cost = 0;
    int rating = 0;

    // check if file opened correctly.
    if (file.is_open())
    {
        // process data.
        while (std::getline(file,line) )
        {
            if (line == "GAME")
            {
                lineCounter = 0;
            }
            
            if (lineCounter == 1)       // ID.
            {
                id = std::stoi(line);
            }
            else if (lineCounter == 2)  // Name.
            {
                name = line;
            }
            else if (lineCounter == 3)  // Description.
            {
                desc = line;
            }
            else if (lineCounter == 4)  // Cost.
            {
                cost = std::stoi(line);
            }
            else if (lineCounter == 5)  // Rating.
            {
                rating = std::stoi(line);

                // create game.
                Game game(name, desc, cost, rating, id);
                games.addAtEnd(game);
            }

            lineCounter++;
        }

        file.close();
    }

    return games;
}

void Utils::savefile()
{
}
