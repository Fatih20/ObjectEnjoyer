#include "PlayerInGameCandy.hpp"
#include <algorithm>

using namespace std;
PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> deckGame, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
{
    for (int i = 0; i < numberOfPlayer; i++)
    {
        this->players.at(turns.at(i)).drawCard(deckGame, 2);
    }
};

bool PlayerInGameCandy::usernameExist(string username)
{
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = players.at(i).getUsername() == username;
    }
    return found;
}

void PlayerInGameCandy::createAndAddPlayer(int gameID)
{
    PlayerCandy p(gameID);
    bool usernameUnique = !usernameExist(p.getUsername());
    while (!usernameUnique)
    {
        cout << "Username already exists!" << endl;
        p.setValidUsername();
        usernameUnique = !usernameExist(p.getUsername());
    }
    players.push_back(p);
}

void PlayerInGameCandy::showLeaderboard()
{
    vector<PlayerCandy> sortedPlayers = players;
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

void PlayerInGameCandy::removePlayerOfID(int removedID)
{
    auto iterator = find_if(this->players.begin(), this->players.end(), [removedID](PlayerCandy p) -> bool
                            { return p.getGameID() == removedID; });

    if (iterator != this->players.end())
    {
        remove(iterator - this->players.begin());
    }
}

int PlayerInGameCandy::correctedIndex(int rawIndex)
{
    int indexOfCurrentPlayer = getIndexOfCurrentTurn();
    return rawIndex < indexOfCurrentPlayer ? rawIndex : rawIndex + 1;
}

void PlayerInGameCandy::redrawCardForCurrentPlayer(DeckGame<ColorCard> &deckGame)
{
    getPlayerWithTurn().redrawCard(deckGame);
};

void PlayerInGameCandy::showPlayerExceptCurrent()
{
    int numberOfPlayer = getNumberOfPlayer();
    int indexOfCurrentTurn = getIndexOfCurrentTurn();
    int numbering = 0;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        if (i != indexOfCurrentTurn)
        {
            cout << players.at(i) << endl;
            numbering++;
        }
    }
};