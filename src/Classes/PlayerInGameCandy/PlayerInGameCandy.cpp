#include "PlayerInGameCandy.hpp"
#include <algorithm>

using namespace std;

PlayerInGameCandy::PlayerInGameCandy(int numberOfPlayer, int turn, bool directionIsLeft) : PlayerInGame(numberOfPlayer, turn, directionIsLeft){

                                                                                           };

void PlayerInGameCandy::showLeaderboard()
{
    vector<Player> sortedPlayers = players;
    sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player p1, Player p2) -> bool
         { return p1 > p2; });
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ".";
        sortedPlayers.at(i).getScore();
    }
}

void PlayerInGameCandy::reverse()
{
    reverseTurn();
}