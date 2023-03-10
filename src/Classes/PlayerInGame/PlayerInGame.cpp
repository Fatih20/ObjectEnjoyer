#include "PlayerInGame.hpp"
#include <iostream>

using namespace std;

PlayerInGame::PlayerInGame() : PlayerCollection(0)
{
}

PlayerInGame::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    directionIsLeft = false;
    turn = 1;
}

PlayerInGame::PlayerInGame(int numberOfPlayer, int turn, int directionIsLeft) : PlayerCollection(numberOfPlayer)
{
    this->directionIsLeft = directionIsLeft;
    this->turn = (turn % numberOfPlayer) + 1;
}

void PlayerInGame::setTurn(int newTurn)
{
    turn = newTurn;
}

void PlayerInGame::reverseTurn()
{
    directionIsLeft = !directionIsLeft;
}

bool PlayerInGame::getTurn()
{
    return turn;
}

void PlayerInGame::nextTurn()
{
    int newTurn = getTurn() + directionIsLeft ? -1 : 1;
    int numberOfPlayer = getNumberOfPlayer();
    newTurn = (numberOfPlayer + (newTurn % numberOfPlayer)) % numberOfPlayer;
    turn = newTurn;
}

void PlayerInGame::showPlayer()
{
    for (int i = 0; i < players.size(); i++)
    {
        cout << i + 1 << ". " << players.at(i).getUsername() << endl;
    }
};

void PlayerInGame::showPlayerExcept(int unprintedID)
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