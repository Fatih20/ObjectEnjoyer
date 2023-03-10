#include "Player.hpp"
#include "PlayerException/PlayerException.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

vector<string> Player::allNicknames(0);
int Player::numberOfPlayer = 0;

Player::Player()
{
    numberOfPlayer++;
    score = 0;
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
    cout << "Masukkan username player ke-" << numberOfPlayer << " : ";
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

string Player::getUsername() const
{
    return username;
}

Player::Player(const Player &givenPlayer)
{
    numberOfPlayer++;
    username = givenPlayer.getUsername();
    allNicknames.push_back(username);
};

void Player::operator=(const Player &givenPlayer)
{
    numberOfPlayer++;
    username = givenPlayer.getUsername();
    allNicknames.push_back(username);
};

int Player::getScore()
{
    return score;
}

void Player::addScore(int addedScore)
{
    score += addedScore;
}

void Player::subtractScore(int subtractedScore)
{
    score -= subtractedScore;
}

void Player::operator+=(int addedScore)
{
    addScore(addedScore);
};

void Player::operator-=(int subtractedScore)
{
    subtractScore(subtractedScore);
}

void Player::resetScore()
{
    score = 0;
}

void Player::printScore()
{
    cout << username << ": " << getScore() << endl;
}