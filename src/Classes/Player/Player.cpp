#include "Player.hpp"
#include "PlayerException/PlayerException.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

Player::Player(int gameID)
{
    this->gameID;
    score = 0;
    username = askForUsername();
    setValidUsername();
};

Player::~Player(){};

void Player::setValidUsername()
{
    username = askForUsername();
    bool validUsername = false;
    while (!validUsername)
    {
        try
        {
            username = askForUsername();
            validUsername = true;
        }
        catch (UsernameExist e)
        {
            cout << "Username " << e.getUsernameThatExist() << " already exists" << endl;
        }
    }
}

string Player::askForUsername()
{
    cout << "Masukkan username player ke-" << gameID << " : ";
    string askedUsername;
    cin >> askedUsername;
    if (askedUsername == "")
    {
        throw UsernameEmpty();
    }
    return askedUsername;
};

string Player::getUsername() const
{
    return username;
};

Player::Player(const Player &givenPlayer)
{
    username = givenPlayer.getUsername();
    gameID = givenPlayer.gameID;
};

Player &Player::operator=(const Player &givenPlayer)
{
    username = givenPlayer.getUsername();
    gameID = givenPlayer.gameID;
    return *this;
};

int Player::getScore()
{
    return score;
};

void Player::addScore(int addedScore)
{
    score += addedScore;
};

void Player::subtractScore(int subtractedScore)
{
    score -= subtractedScore;
};

void Player::operator+=(int addedScore)
{
    addScore(addedScore);
};

void Player::operator-=(int subtractedScore)
{
    subtractScore(subtractedScore);
};

void Player::resetScore()
{
    score = 0;
};

void Player::printScore()
{
    cout << username << ": " << getScore() << endl;
};

int Player::getGameID()
{
    return gameID;
};