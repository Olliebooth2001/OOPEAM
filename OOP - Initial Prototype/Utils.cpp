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

List<Game> Utils::ReadGameDataFromFile(const std::string& directory)
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

// account player, account admin, library item needs to be be in one function.

List<Account> Utils::ProcessFileData(Application& app, const std::string& dir)
{
    // variables for processing data.
    int lineCounter = 0;
    std::string line;
    List<Account> accounts;

    // open file.
    std::ifstream file(dir, std::ios_base::app);

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line == "ACCOUNT")
            {
                std::getline(file, line);           // Date
                Date dateCreated = parseDate(line);  
                
                std::getline(file, line);           // Email
                std::string email = line;
                
                std::getline(file, line);           // Password.
                std::string password = line;


                Account account(email, password, dateCreated);

                std::getline(file, line);

                while ( (line == "ACCOUNT-ADMIN") || (line == "ACCOUNT-PLAYER") )
                {
                    if (line == "ACCOUNT-ADMIN")
                    {
                        std::getline(file, line);           // Date Created
                        Date dateCreated = parseDate(line);

                        std::getline(file, line);           // Username
                        std::string username = line;

                        std::getline(file, line);           // Password
                        std::string password = line;

                        std::getline(file, line);
                        int credits = std::stoi(line);      // Credits.

                        Admin admin = Admin(username,password,dateCreated,credits);

                        std::getline(file, line);
                        while (line == "LIBRARY-ITEM")
                        {
                            std::getline(file, line);           // Game ID
                            int GameID = std::stoi(line);

                            std::getline(file, line);           // Date Purchased
                            Date datePurchased = parseDate(line);

                            std::getline(file, line);           // hours played.
                            float hours = std::stoi(line);

                            std::getline(file, line);
                            Game* tmpGame = nullptr;

                            for (int i = 0; i < app.GetStore().getGames().length(); i++)
                            {
                                if (app.GetStore().getGames()[i]->GetID() == GameID)
                                {
                                    tmpGame = app.GetStore().getGames()[i];
                                }
                            }
                            LibraryItem tmpLibraryItem(datePurchased, tmpGame);
                            admin.library.addInFront(&tmpLibraryItem);
                        }

                        account.getUsers().addInFront(&admin);
                    }
                    else if (line == "ACCOUNT-PLAYER")
                    {
                        std::getline(file, line);           // Date Created
                        Date dateCreated = parseDate(line);

                        std::getline(file, line);           // Username
                        std::string username = line;

                        std::getline(file, line);           // Password
                        std::string password = line;

                        std::getline(file, line);
                        int credits = std::stoi(line);      // Credits.

                        Player player = Player(username, password, dateCreated, credits);

                        std::getline(file, line);
                        while (line == "LIBRARY-ITEM")
                        {
                            std::getline(file, line);           // Game ID
                            int GameID = std::stoi(line);

                            std::getline(file, line);           // Date Purchased
                            Date datePurchased = parseDate(line);

                            std::getline(file, line);           // hours played.
                            float hours = std::stoi(line);

                            std::getline(file, line);
                            Game* tmpGame = nullptr;

                            for (int i = 0; i < app.GetStore().getGames().length(); i++)
                            {
                                if (app.GetStore().getGames()[i]->GetID() == GameID)
                                {
                                    tmpGame = app.GetStore().getGames()[i];
                                }
                            }

                            LibraryItem tmpLibraryItem(datePurchased, tmpGame);
                            player.library.addInFront(&tmpLibraryItem);
                        }

                            //account.getUsers().addInFront(&player);
                            account.addUser(&player);
                        }
                    }
                
                    accounts.addAtEnd(account);
                }
            }
        }
    return accounts;
}

Date Utils::parseDate(const std::string& stringDate)
{
    // variable declarations.
    char delimiter = '-';
    std::string buffer = "";
    //Date date = NULL;
    bool isAtDelim = false;
    int lastNumCounter = 0;
    int section = 0;

    // tmp date values.
    int year, month, day;
    year = month = day = 0;

    for (int i = 0; i < stringDate.size(); i++)
    {
        // push current character of string into the buffer string.
        buffer.push_back(stringDate[i]);

        if (section == 2)
        {
            buffer.push_back(stringDate[i+1]);
        }

        // if delimiter is found...
        if (buffer.back() == delimiter)
        {
            // remove it.
            buffer.erase(std::prev(buffer.end()));
            isAtDelim = true;
        }

        if ( isAtDelim || lastNumCounter == 1 )    // Year.
        {
            if (section == 0)
            {
                year = std::stoi(buffer);
                buffer.clear();
                isAtDelim = false;
            }
            else if (section == 1)
            {
                month = std::stoi(buffer);
                buffer.clear();
                isAtDelim = false;
                lastNumCounter++;
            }
            else if (section == 2)
            {
                day = std::stoi(buffer);
                buffer.clear();
                break;
            }

            section++;
        }
    }

    return Date(day, month, year);
}

void Utils::savefile()
{
}
