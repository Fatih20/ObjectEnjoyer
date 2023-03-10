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
    directionIsLeft = false;
    turn = 1;
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
    return currentTurn + 1;
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