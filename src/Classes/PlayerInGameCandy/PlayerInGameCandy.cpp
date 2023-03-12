#include "PlayerInGameCandy.hpp"
#include "Classes/PlayerInGameException/PlayerInGameException.hpp"
#include <algorithm>

using namespace std;
PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> deckGame, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
{
    for (int i = 0; i < numberOfPlayer; i++)
    {
        this->players.at(turns.at(i)).drawCard(deckGame, 2);
    }
};

PlayerInGameCandy::PlayerInGameCandy(const PlayerInGameCandy &playerInGameCandy) : PlayerInGame<PlayerCandy>(playerInGameCandy)
{
}

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

int PlayerInGameCandy::correctedIndexCurrent(int rawIndex)
{
    vector<int> exceptedIndex = {getIndexOfCurrentTurn()};
    return correctedIndexCustom(rawIndex, exceptedIndex);

    // int indexOfCurrentPlayer = getIndexOfCurrentTurn();
    // return rawIndex < indexOfCurrentPlayer ? rawIndex : rawIndex + 1;
}

void PlayerInGameCandy::redrawCardForCurrentPlayer(DeckGame<ColorCard> &deckGame)
{
    getPlayerWithTurn().redrawCard(deckGame);
};

void PlayerInGameCandy::showPlayerExcept(vector<int> exceptedIndex)
{
    int numberOfPlayer = getNumberOfPlayer();
    int indexOfCurrentTurn = getIndexOfCurrentTurn();
    int numbering = 0;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        if (exceptedIndex.end() != find(exceptedIndex.begin(), exceptedIndex.end(), i))
        {
            cout << numbering + 1 << ". " << players.at(i) << endl;
            numbering++;
        }
    }
};

void PlayerInGameCandy::showPlayerExceptCurrent()
{
    vector<int> exceptedIndex = {getIndexOfCurrentTurn()};
    showPlayerExcept(exceptedIndex);
};

void PlayerInGameCandy::swapDeckOfCurrentWith(int rawTargetIndex)
{
    // int targetIndex;
    // try
    // {
    //     targetIndex = correctedIndexCurrent(rawTargetIndex);
    // }
    // catch (OutOfBoundIndex e)
    // {
    //     e.setMessage("Pilihan pemain sasaran ada di luar opsi!");
    //     throw e;
    // }
    PlayerCandy &playerSource = getPlayerWithTurn();
    PlayerCandy &playerTarget = players.at(rawTargetIndex);
    playerSource.swapDeck(playerTarget);
};

void PlayerInGameCandy::swapDeckOfPlayer(int rawSourceIndex, int rawTargetIndex)
{
    // int sourceIndex;
    // try
    // {
    //     sourceIndex = correctedIndex(rawSourceIndex);
    // }
    // catch (OutOfBoundIndex e)
    // {
    //     e.setMessage("Pilihan pemain pertama ada di luar opsi!");
    // }
    // int targetIndex;
    // try
    // {
    //     targetIndex = correctedIndex(rawTargetIndex);
    // }
    // catch (OutOfBoundIndex e)
    // {
    //     e.setMessage("Pilihan pemain kedua ada di luar opsi!");
    //     throw e;
    // }
    PlayerCandy &playerSource = players.at(rawSourceIndex);
    PlayerCandy &playerTarget = players.at(rawTargetIndex);
    playerSource.swapDeck(playerTarget);
};

int PlayerInGameCandy::correctedIndexCustom(int rawIndex, vector<int> exceptedIndexes)
{
    if (rawIndex < 0 || rawIndex >= getNumberOfPlayer() - exceptedIndexes.size())
    {
        OutOfBoundIndex e;
        throw e;
    }
    auto exceptedIndexesIt = exceptedIndexes.begin();
    bool foundLimit = false;
    int resultIndex = rawIndex;
    for (exceptedIndexesIt = exceptedIndexes.begin(); !foundLimit && exceptedIndexesIt != exceptedIndexes.end();
         exceptedIndexesIt++)
    {
        foundLimit = resultIndex > *exceptedIndexesIt;
        if (!foundLimit)
        {
            resultIndex++;
        }
    }
    return resultIndex;
};

std::vector<string> PlayerInGameCandy::getWinner()
{
    vector<string> winnerUsernames;
    int limit = pow(2, 32);
    for (auto playerIterator = players.begin(); playerIterator != players.end(); playerIterator++)
    {
        double score = playerIterator->getScore();
        if (score == limit || score < limit)
        {
            winnerUsernames.push_back(playerIterator->getUsername());
        }
    }
    return winnerUsernames;
};
bool PlayerInGameCandy::winnerExist()
{
    return players.end() != find_if(players.begin(), players.end(), [](PlayerCandy p) -> bool
                                    { return p.getScore() > pow(2, 32); });
};
