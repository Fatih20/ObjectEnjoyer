#include "PlayerInGameCandy.hpp"
#include "../PlayerInGameException/PlayerInGameException.hpp"
#include <algorithm>

using namespace std;

// PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> &deckGame, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
// {
//     for (int i = 0; i < numberOfPlayer; i++)
//     {
//         createAndAddPlayer(i + 1);
//     }
//     for (int i = 0; i < numberOfPlayer; i++)
//     {
//         this->players.at(turns.at(i)).drawCard(deckGame, 2);
//     }
// };

// PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> &deckGame, DeckGame<AbilityCard> &deckAbility, int numberOfPlayer) : PlayerInGameCandy(deckGame, numberOfPlayer)
// {
//     cout << "Entered deck ability involved constructor in pigc" << endl;
//     for (int i = 0; i < numberOfPlayer; i++)
//     {
//         cout << "Player " << i << "th drawing ability cards" << endl;
//         this->players.at(turns.at(i)).drawAbility(deckAbility);
//     }
//     cout << "Exited deck ability involved constructor in pigc" << endl;
// };

PlayerInGameCandy::PlayerInGameCandy() : PlayerInGame<PlayerCandy>(0){};

PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> &deckGame, DeckGame<AbilityCard> &deckAbility, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
{
    for (int i = 0; i < numberOfPlayer; i++)
    {
        createAndAddPlayer(i + 1);
    }
    drawColorCardAll(deckGame);
    drawAbilityCardAll(deckAbility);
    reversedThisRoundInfo = make_pair(false, -1);
};

PlayerInGameCandy::PlayerInGameCandy(const PlayerInGameCandy &playerInGameCandy) : PlayerInGame<PlayerCandy>(playerInGameCandy)
{
    reversedThisRoundInfo = make_pair(false, -1);
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

bool PlayerInGameCandy::usernameExist(string username, int gameID)
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
    while (usernameExist(p.getUsername()))
    {
        cout << "Username itu sudah dipakai! Pilih yang lain." << endl;
        p.setValidUsername();
    }
    players.push_back(p);
}

void PlayerInGameCandy::showLeaderboard()
{
    vector<PlayerCandy> sortedPlayers = players;
    sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player<ColorCard> p1, Player<ColorCard> p2) -> bool
         { return p1 > p2; });
    int numberOfPlayer = getNumberOfPlayer();
    cout << "\033[1m\033[37m"
         << "Leaderboard: "
         << "\033[0m" << endl;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << "  " << i + 1 << ". Player " << sortedPlayers.at(i).getGameID() << "  : ";
        printf("%.2f", sortedPlayers.at(i).getScore());
        cout << endl;
    }
}

void PlayerInGameCandy::reverseTurnInitial()
{
    reversedThisRoundInfo = make_pair(true, getCurrentTurn());
    reverse(players.begin() + getCurrentTurn() + 1, players.end());
}

void PlayerInGameCandy::resetRound()
{
    PlayerInGame::resetRound();
    if (reversedThisRoundInfo.first)
    {

        rotate(turns.begin(), turns.begin() + 1, turns.end());
    }
    else
    {
        reverseTurnPost(reversedThisRoundInfo.second);
    }
    reversedThisRoundInfo = make_pair(false, -1);
    cout << "Resetting round at pigc" << endl;
}

void PlayerInGameCandy::reverseTurnPost(int pivotIndex)
{
    reverse(turns.begin(), turns.begin() + pivotIndex + 1);
    reverse(turns.begin() + pivotIndex, turns.end());
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
}

void PlayerInGameCandy::redrawCardForCurrentPlayer(DeckGame<ColorCard> &deckGame)
{
    getPlayerWithTurn().redrawCard(deckGame);
};

void PlayerInGameCandy::redrawAll(DeckGame<ColorCard> &deckGame)
{
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        players.at(turns.at(i)).redrawCard(deckGame);
    }
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
    int index = correctedIndexCurrent(rawTargetIndex);
    PlayerCandy &playerSource = getPlayerWithTurn();
    PlayerCandy &playerTarget = players.at(index);
    playerSource.swapDeck(playerTarget);
};

void PlayerInGameCandy::swapCardOfPlayer(int sourceIndex, int targetIndex, bool firstLeft, bool secondLeft)
{
    PlayerCandy &playerSource = players.at(sourceIndex);
    PlayerCandy &playerTarget = players.at(targetIndex);
    ColorCard firstRightCard = playerSource.ejectCard();
    ColorCard firstLeftCard = playerSource.ejectCard();

    ColorCard secondRightCard = playerTarget.ejectCard();
    ColorCard secondLeftCard = playerTarget.ejectCard();

    ColorCard temp;
    if (firstLeft)
    {
        if (secondLeft)
        {
            swap(firstLeftCard, secondLeftCard);
        }
        else
        {
            swap(firstLeftCard, secondLeftCard);
        }
    }
    else
    {
        if (secondLeft)
        {
            swap(firstRightCard, secondLeftCard);
        }
        else
        {
            swap(firstRightCard, secondRightCard);
        }
    }

    playerSource += firstLeftCard;
    playerSource += firstRightCard;

    playerTarget += secondLeftCard;
    playerTarget += secondRightCard;
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

string PlayerInGameCandy::getWinner()
{
    unsigned int limit = pow(2, 32);
    bool found = false;
    string winnerUsername;
    for (auto playerIterator = players.begin(); playerIterator != players.end() && !found; playerIterator++)
    {
        double score = playerIterator->getScore();
        if (score == limit || score < 0)
        {
            winnerUsername = (playerIterator->getUsername());
            found = true;
        }
    }
    return winnerUsername;
};

bool PlayerInGameCandy::winnerExist()
{
    unsigned int limit = pow(2, 32);
    return players.end() != find_if(players.begin(), players.end(), [limit](PlayerCandy p) -> bool
                                    { return p.getScore() > limit || p.getScore() < 0; });
};

void PlayerInGameCandy::drawAbilityCardAll(DeckGame<AbilityCard> &deckAbility)
{
    // cout << "Entering the drawing of the cards" << endl;
    // cout << deckAbility << endl;
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        players.at(turns.at(i)).drawAbility(deckAbility);
        players.at(turns.at(i)).test();
    }
};

void PlayerInGameCandy::drawColorCardAll(DeckGame<ColorCard> &deckColor)
{
    cout << "Drawing color card" << endl;
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        players.at(turns.at(i)).drawCard(deckColor, 2);
        cout << "Deck of " << turns.at(i) << "'th player" << endl;
        players.at(turns.at(i)).printCard();
    }
};

bool PlayerInGameCandy::disablePlayerAbility(int index)
{
    bool succesful = players.at(index).getAbilityAvailable();
    players.at(index).disableAbility();
    return succesful;
}

bool PlayerInGameCandy::playerIndexInRange(int index)
{
    return index >= 0 && index < getNumberOfPlayer();
}
void PlayerInGameCandy::rewardHighestCombination(unsigned int reward, DeckGame<ColorCard> &tableCard)
{
    int indexOfHighest = 0;
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 1; i < numberOfPlayer; i++)
    {
        if (players.at(i).higherCombinationWeight(players.at(indexOfHighest), tableCard))
        {
            indexOfHighest = i;
        }
    }
    players.at(indexOfHighest) += reward;
}
