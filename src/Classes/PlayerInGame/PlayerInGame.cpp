#include "PlayerInGame.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

PlayerInGame::PlayerInGame() : PlayerCollection(0)
{
    PlayerInGame(0);
}

PlayerInGame::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    vector<int> turns(numberOfPlayer);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        turns[i] = i + 1;
    }
    currentTurn = 0;
    roundComplete = false;
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

    // Only increment current turn when the turn is still in range
    currentTurn += currentTurn < getNumberOfPlayer() ? 1 : 0;

    // Set the roundComplete to true once the last player is done
    roundComplete = currentTurn >= getNumberOfPlayer();
}

bool PlayerInGame::getIsRoundComplete()
{
    return roundComplete;
}

void PlayerInGame::resetRoundStatus()
{
    roundComplete = false;
};
void PlayerInGame::stopRound()
{
    roundComplete = true;
};
