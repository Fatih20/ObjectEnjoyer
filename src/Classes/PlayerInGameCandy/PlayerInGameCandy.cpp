#include "PlayerInGameCandy.hpp"
#include <algorithm>

using namespace std;
PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> deckGame, int numberOfPlayer) : PlayerInGame<ColorCard>(deckGame, 2, numberOfPlayer){

                                                                                         };

void PlayerInGameCandy::showLeaderboard()
{
    vector<Player<ColorCard>> sortedPlayers = players;
    sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player<ColorCard> p1, Player<ColorCard> p2) -> bool
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
    reverse(players.begin() + getCurrentTurn(), players.end());
}

void PlayerInGameCandy::resetRound()
{
    PlayerInGame::resetRound();
    rotate(turns.begin(), turns.begin() + 1, turns.end());
}