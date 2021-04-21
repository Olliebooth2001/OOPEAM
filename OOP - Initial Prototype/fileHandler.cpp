#include "fileHandler.h"

#include <fstream>

List<Game> fileHandler::ReadGameDataFromFile(const std::string& dir)
{
    // declare/initialise variables.
    int lineCounter = 0;
    std::string line;
    List<Game> games;

    // open file.
    std::ifstream file(dir, std::ios_base::app);

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
        while (std::getline(file, line))
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

List<Account*> fileHandler::ProcessFileData(Application& app, const std::string& dir)
{
    // variables for processing data.
    int lineCounter = 0;
    std::string line;
    List<Account*> accounts;

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


                Account* account = new Account(email, password, dateCreated);

                std::getline(file, line);

                while ((line == "ACCOUNT-ADMIN") || (line == "ACCOUNT-PLAYER"))
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

                        Admin* admin = new Admin(username, password, dateCreated, credits);

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
                            LibraryItem* tmpLibraryItem = new LibraryItem(datePurchased, tmpGame, hours);
                            admin->library.push_back(tmpLibraryItem);
                        }



                        account->addUser(admin);
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

                        Player* player = new Player(username, password, dateCreated, credits);

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

                            LibraryItem* tmpLibraryItem = new LibraryItem(datePurchased, tmpGame, hours);
                            player->library.push_back(tmpLibraryItem);
                        }

                        //account.getUsers().addInFront(&player);
                        account->addUser(player);

                    }
                }

                accounts.addAtEnd(account);
            }
        }
    }

    return accounts;
}

Date fileHandler::parseDate(const std::string& stringDate)
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
            buffer.push_back(stringDate[i + 1]);
        }

        // if delimiter is found...
        if (buffer.back() == delimiter)
        {
            // remove it.
            buffer.erase(std::prev(buffer.end()));
            isAtDelim = true;
        }

        if (isAtDelim || lastNumCounter == 1)    // Year.
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

void fileHandler::saveToFile(Application& app, const std::string& dir)
{
    // open file.
    std::ofstream file(dir);
    
    if (file.is_open())
    {
        // save Game information.
        for (int i = 0; i < app.GetStore().getGames().length(); i++)
        {
            file << "GAME" << std::endl;
            file << app.GetStore().getGames()[i]->GetID() << std::endl;
            file << app.GetStore().getGames()[i]->GetName() << std::endl;
            file << app.GetStore().getGames()[i]->GetDescription() << std::endl;
            file << app.GetStore().getGames()[i]->GetCost() << std::endl;
            file << app.GetStore().getGames()[i]->GetRating() << std::endl;
        }

        // save Account information.
        for (int i = 0; i < app.accounts.length(); i++)
        {
            file << "ACCOUNT" << std::endl;
            file << app.accounts[i]->getDateCreatedAsString() << std::endl;
            file << app.accounts[i]->getEmail() << std::endl;
            file << app.accounts[i]->getPassword() << std::endl;
        }

        // save Account Player & Admin information.
        for (int i = 0; i < app.accounts.length(); i++)
        {
            for (int j = 0; j < app.accounts[i]->getUsers().length(); j++)
            {
                // Is the user an admin?..
                if (app.accounts[i]->getUsers()[j]->HasPermissions())
                {
                    file << "ACCOUNT-ADMIN" << std::endl;
                }
                else // otherwise its a player..
                {
                    file << "ACCOUNT-PLAYER" << std::endl;
                }
                
                file << app.accounts[i]->getUsers()[j]->getDateAsString() << std::endl;
                file << app.accounts[i]->getUsers()[j]->GetUsername() << std::endl;
                file << app.accounts[i]->getUsers()[j]->GetPassword() << std::endl;
                file << app.accounts[i]->getUsers()[j]->GetCredit() << std::endl;
            }
        }

        // save Library-Item information.
        for (int i = 0; i < app.accounts.length(); i++)
        {
            for (int j = 0; j < app.accounts[i]->getUsers().length(); j++)
            {
                for (int k = 0; k < app.accounts[i]->getUsers()[j]->GetLibrary().size(); k++)
                {
                    file << "LIBRARY-ITEM" << std::endl;

                    file << app.accounts[i]->getUsers()[j]->GetLibrary()[k]->GetLibraryGame()->GetID() << std::endl;
                    file << app.accounts[i]->getUsers()[j]->GetLibrary()[k]->getPurchaseDate().GetDate() << std::endl;
                    file << app.accounts[i]->getUsers()[j]->GetLibrary()[k]->GetGameTime() << std::endl;
                }
                
            }
        }
        file.close();
    }
}

