#include "PlayerInGameCandy.hpp"
#include <algorithm>

using namespace std;
PlayerInGameCandy::PlayerInGameCandy(int numberOfPlayer, int currentTurn) : PlayerInGame(numberOfPlayer, currentTurn){

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

void PlayerInGameCandy::reverseTurn()
{
    reverse(players.begin() + getNthPlayerWithTurn(), players.end());
}

void PlayerInGameCandy::resetRound()
{
    PlayerInGame::resetRound();
    rotate(turns.begin(), turns.begin() + 1, turns.end());
}