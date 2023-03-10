#include "PlayerInGame.hpp"
#include <iostream>

using namespace std;

template <class T>
PlayerInGame<T>::PlayerInGame() : PlayerCollection(0)
{
}
template <class T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    directionIsLeft = false;
    turn = 1;
}
template <class T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer, int turn, int directionIsLeft) : PlayerCollection(numberOfPlayer)
{
    this->directionIsLeft = directionIsLeft;
    this->turn = (turn % numberOfPlayer) + 1;
}
template <class T>
void PlayerInGame<T>::setTurn(int newTurn)
{
    turn = newTurn;
}
template <class T>
void PlayerInGame<T>::reverseTurn()
{
    directionIsLeft = !directionIsLeft;
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

template class PlayerInGame<int>;