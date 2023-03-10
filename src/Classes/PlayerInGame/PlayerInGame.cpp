#include "PlayerInGame.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
PlayerInGame<T>::PlayerInGame() : PlayerCollection(0)
{
    PlayerInGame(0);
}
template <class T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    vector<int> turns(numberOfPlayer);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        turns[i] = i + 1;
    }
    currentTurn = 0;
    roundComplete = false;
}

template <class T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer, int currentTurn) : PlayerCollection(numberOfPlayer)
{
    PlayerInGame(number);
    this->currentTurn = currentTurn - 1;
}

template <class T>
void PlayerInGame<T>::setTurn(int newTurn)
{
    int numberOfPlayer = getNumberOfPlayer();
    currentTurn = (((newTurn - 1) % numberOfPlayer) + numberOfPlayer) % numberOfPlayer;
}
template <class T>
void PlayerInGame<T>::reverseTurn()
{
    reverse(turns.begin(), turns.end());
}
template <class T>
bool PlayerInGame<T>::getTurn()
{
    return turn;
}
template <class T>
void PlayerInGame<T>::nextTurn()
{
    int newTurn = getTurn() + directionIsLeft ? -1 : 1;
    int numberOfPlayer = getNumberOfPlayer();
    newTurn = (numberOfPlayer + (newTurn % numberOfPlayer)) % numberOfPlayer;
    turn = newTurn;
}
template <class T>
void PlayerInGame<T>::showPlayer()
{
    for (int i = 0; i < players.size(); i++)
    {
        cout << i + 1 << ". " << players.at(i).getUsername() << endl;
    }
};
template <class T>
void PlayerInGame<T>::showPlayerExcept(int unprintedID)
{
    bool print = true;
    int index = 0;
    for (int i = 0; i < players.size(); i++)
    {
        if (players.at(i).getGameID() != unprintedID)
        {
            cout << index + 1 << ". " << players.at(i).getUsername() << endl;
            index++;
        }
    }
}
template <class T>
void PlayerInGame<T>::removePlayerOfID(int removedID)
{
    // To do : Erase from turn list as well
    for (int i = 0; i < players.size(); i++)
    {
        if (players.at(i).getGameID() == removedID)
        {
            players.erase(players.begin() + i);
        }
    };
}

// template <class T>

template <class T>
Player &PlayerInGame<T>::getPlayerWithTurn()
{
    return players.at(currentTurn);
}

template <class T>
int PlayerInGame<T>::getNthPlayerWithTurn()
{
    return currentTurn + 1;
}

template <class T>
void PlayerInGame<T>::nextTurn()
{

    // Only increment current turn when the turn is still in range
    currentTurn += currentTurn < getNumberOfPlayer() ? 1 : 0;

    // Set the roundComplete to true once the last player is done
    roundComplete = currentTurn >= getNumberOfPlayer();
}

template <class T>
bool PlayerInGame<T>::getIsRoundComplete()
{
    return roundComplete;
}

template <class T>
void PlayerInGame<T>::resetRound()
{
    roundComplete = false;
};
template <class T>
void PlayerInGame<T>::stopRound()
{
    roundComplete = true;
};

template class PlayerInGame<int>;
