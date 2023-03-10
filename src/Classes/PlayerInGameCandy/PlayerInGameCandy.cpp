#include "PlayerInGameCandy.hpp"
#include <algorithm>

using namespace std;

using namespace std;
PlayerInGameCandy::PlayerInGameCandy(int numberOfPlayer, int currentTurn) : PlayerInGame(numberOfPlayer, currentTurn){

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

void PlayerInGameCandy::reverseTurn()
{
    reverse(players.begin() + getNthPlayerWithTurn(), players.end());
}

void PlayerInGameCandy::resetRound()
{
    PlayerInGame::resetRound();
    rotate(turns.begin(), turns.begin() + 1, turns.end());
}