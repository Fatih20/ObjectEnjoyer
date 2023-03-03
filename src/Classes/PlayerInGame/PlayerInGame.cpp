#include "PlayerInGame.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

PlayerInGame::PlayerInGame() : PlayerCollection(0)
{
}

PlayerInGame::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    vector<int> turns(numberOfPlayer);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        turns[i] = i + 1;
    }
    currentTurn = 0;
}

PlayerInGame::PlayerInGame(int numberOfPlayer, int currentTurn) : PlayerCollection(numberOfPlayer)
{
    PlayerInGame(numberOfPlayer);
    this->currentTurn = currentTurn - 1;
}

void PlayerInGame::setTurn(int newTurn)
{
    int numberOfPlayer = getNumberOfPlayer();
    currentTurn = (((newTurn - 1) % numberOfPlayer) + numberOfPlayer) % numberOfPlayer;
}

void PlayerInGame::reverseTurn()
{
    reverse(turns.begin(), turns.end());
}

Player &PlayerInGame::getPlayerWithTurn()
{
    return players.at(currentTurn);
}

int PlayerInGame::getNthPlayerWithTurn()
{
    return currentTurn++;
}

void PlayerInGame::nextTurn()
{
    currentTurn++;
    int numberOfPlayer = getNumberOfPlayer();
    currentTurn = ((currentTurn % numberOfPlayer) + numberOfPlayer) % numberOfPlayer;
}
