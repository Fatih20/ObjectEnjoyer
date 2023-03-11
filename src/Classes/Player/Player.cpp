#include "Player.hpp"
#include "Classes/InventoryHolder/InventoryHolder.hpp"
#include "../PlayerException/PlayerException.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

template <typename T>
Player<T>::Player()
{
    this->gameID = 0;
    username = "";
    score = 0;
}

template <typename T>
Player<T>::Player(int gameID)
{
    this->gameID;
    score = 0;
    username = askForUsername();
    setValidUsername();
};

template <typename T>
Player<T>::~Player(){};

template <typename T>
void Player<T>::setValidUsername()
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
        catch (UsernameEmpty e)
        {
            cout << e.getMessage() << endl;
        }
    }
};

template <typename T>
string Player<T>::askForUsername()
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

template <typename T>
string Player<T>::getUsername() const
{
    return username;
};

template <typename T>
Player<T>::Player(const Player &givenPlayer)
{
    username = givenPlayer.getUsername();
    gameID = givenPlayer.gameID;
};

template <typename T>
Player<T> &Player<T>::operator=(const Player<T> &givenPlayer)
{
    username = givenPlayer.getUsername();
    gameID = givenPlayer.gameID;
    return *this;
};

template <typename T>
int Player<T>::getScore()
{
    return score;
};

template <typename T>
void Player<T>::addScore(int addedScore)
{
    score += addedScore;
};

template <typename T>
void Player<T>::subtractScore(int subtractedScore)
{
    score -= subtractedScore;
};

template <typename T>
void Player<T>::operator+=(int addedScore)
{
    addScore(addedScore);
};

template <typename T>
void Player<T>::operator-=(int subtractedScore)
{
    subtractScore(subtractedScore);
};

template <typename T>
void Player<T>::resetScore()
{
    score = 0;
};

template <typename T>
void Player<T>::printScore()
{
    cout << username << ": " << getScore() << endl;
};

template <typename T>
int Player<T>::getGameID()
{
    return gameID;
};