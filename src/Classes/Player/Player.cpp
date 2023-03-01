#include "Player.hpp"
#include "PlayerException/PlayerException.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

vector<string> Player::allNicknames(0);
int Player::playerNumber = 0;

Player::Player()
{
    playerNumber += 1;
    bool validUsername = false;
    while (!validUsername)
    {
        try
        {
            username = askForUsername();
            validUsername = true;
        }
        catch (UsernameEmpty e)
        {
            cout << "Cannot have empty username!" << endl;
        }
        catch (UsernameExist e)
        {
            cout << "Username " << e.getUsernameThatExist() << " already exists" << endl;
        }
    }

    allNicknames.push_back(username);
};

Player::~Player()
{
    bool usernameFound = false;
    int i;
    for (i = 0; i < allNicknames.size() && !usernameFound; i += (usernameFound ? 0 : 1))
    {
        usernameFound = allNicknames.at(i) == this->username;
    };
    if (usernameFound)
    {
        allNicknames.erase(allNicknames.begin() + i);
    }
}

string Player::askForUsername()
{
    cout << "Masukkan username player ke-" << playerNumber << " : ";
    string askedUsername;
    cin >> askedUsername;
    if (askedUsername == "")
    {
        throw UsernameEmpty();
    }
    else if (find(allNicknames.begin(), allNicknames.end(), askedUsername) != allNicknames.end())
    {
        throw UsernameExist(askedUsername);
    }

    return askedUsername;
}