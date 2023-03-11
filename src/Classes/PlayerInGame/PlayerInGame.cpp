#include "PlayerInGame.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
PlayerInGame<T>::PlayerInGame() : PlayerCollection<T>(0)
{
    PlayerInGame(0);
};
template <typename T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer) : PlayerCollection<T>(numberOfPlayer)
{
    vector<int> turns(numberOfPlayer);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        turns[i] = i + 1;
    }
    currentTurn = 0;
    roundComplete = false;
};

template <typename T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer, int currentTurn) : PlayerCollection<T>(numberOfPlayer)
{
    PlayerInGame(number);
    this->currentTurn = currentTurn - 1;
};

template <typename T>
void PlayerInGame<T>::setTurn(int newTurn)
{
    int numberOfPlayer = this->getNumberOfPlayer();
    currentTurn = (((newTurn - 1) % numberOfPlayer) + numberOfPlayer) % numberOfPlayer;
};
template <typename T>
void PlayerInGame<T>::reverseTurn()
{
    reverse(turns.begin(), turns.end());
};
template <typename T>
bool PlayerInGame<T>::getTurn()
{
    return currentTurn + 1;
};

template <typename T>
void PlayerInGame<T>::removePlayerOfID(int removedID)
{
    // To do : Erase from turn list as well
    for (int i = 0; i < this->players.size(); i++)
    {
        if (this->players.at(i).getGameID() == removedID)
        {
            this->players.erase(this->players.begin() + i);
        }
    };
};

// template <typename T>

template <typename T>
Player<T> &PlayerInGame<T>::getPlayerWithTurn()
{
    return this->players.at(currentTurn);
};

template <typename T>
int PlayerInGame<T>::getNthPlayerWithTurn()
{
    return currentTurn + 1;
};

template <typename T>
void PlayerInGame<T>::nextTurn()
{

    // Only increment current turn when the turn is still in range
    currentTurn += currentTurn < this->getNumberOfPlayer() ? 1 : 0;

    // Set the roundComplete to true once the last player is done
    roundComplete = currentTurn >= this->getNumberOfPlayer();
};

template <typename T>
bool PlayerInGame<T>::getIsRoundComplete()
{
    return roundComplete;
};

template <typename T>
void PlayerInGame<T>::resetRound()
{
    roundComplete = false;
};
template <typename T>
void PlayerInGame<T>::stopRound()
{
    roundComplete = true;
};

template <typename T>
void PlayerInGame<T>::showPlayer()
{
    for (int i = 0; i < this->players.size(); i++)
    {
        cout << i + 1 << ". " << this->players.at(i).getUsername() << endl;
    }
};

template <typename T>
void PlayerInGame<T>::showPlayerExcept(int unprintedID)
{
    bool print = true;
    int index = 0;
    for (int i = 0; i < this->players.size(); i++)
    {
        if (this->players.at(i).getGameID() != unprintedID)
        {
            cout << index + 1 << ". " << this->players.at(i).getUsername() << endl;
            index++;
        }
    }
};

template class PlayerInGame<ColorCard>;
