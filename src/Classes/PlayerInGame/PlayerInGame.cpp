#include "PlayerInGame.hpp"
#include <iostream>

using namespace std;

PlayerInGame::PlayerInGame() : PlayerCollection(0)
{
}

PlayerInGame::PlayerInGame(int numberOfPlayer) : PlayerCollection(numberOfPlayer)
{
    directionIsLeft = true;
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