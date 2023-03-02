#include "PlayerInGameCandy.hpp"

PlayerInGameCandy::PlayerInGameCandy(int numberOfPlayer, int turn, bool directionIsLeft) : PlayerInGame(numberOfPlayer, turn, directionIsLeft){

                                                                                           };

void PlayerInGameCandy::showLeaderboard()
{
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ".";
        players.at(i).getScore();
    }
}

void PlayerInGameCandy::reverse()
{
    reverseTurn();
}