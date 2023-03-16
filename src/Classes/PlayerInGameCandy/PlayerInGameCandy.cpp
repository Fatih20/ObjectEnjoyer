#include "PlayerInGameCandy.hpp"
#include "../PlayerInGameException/PlayerInGameException.hpp"
#include "../PlayerMini/PlayerMini.hpp"
#include <algorithm>

using namespace std;

PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> &deckGame, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
{
    for (int i = 0; i < numberOfPlayer; i++)
    {
        createAndAddPlayer(i + 1);
    }
    drawColorCardAll(deckGame);
};

PlayerInGameCandy::PlayerInGameCandy() : PlayerInGame<PlayerCandy>(0){};

PlayerInGameCandy::PlayerInGameCandy(DeckGame<ColorCard> &deckGame, DeckGame<AbilityCard> &deckAbility, int numberOfPlayer) : PlayerInGame<PlayerCandy>(numberOfPlayer)
{
    for (int i = 0; i < numberOfPlayer; i++)
    {
        createAndAddPlayer(i + 1);
    }
    this->drawColorCardAll(deckGame);
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
        found = getNthPlayer(i).getUsername() == username;
    }
    return found;
}

bool PlayerInGameCandy::usernameExist(string username, int gameID)
{
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = getNthPlayer(i).getUsername() == username;
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
    players.emplace_back(p);
}

void PlayerInGameCandy::showLeaderboard()
{
    vector<PlayerMini<ColorCard>> vectorOfPMini;
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        PlayerMini<ColorCard> pM(players.at(i));
        vectorOfPMini.push_back(pM);
    }
    sort(vectorOfPMini.begin(), vectorOfPMini.end(), [](PlayerMini<ColorCard> p1, PlayerMini<ColorCard> p2) -> bool
         { return p1 > p2; });
    cout << "\033[1m\033[37m"
         << "Leaderboard: "
         << "\033[0m" << endl;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ". " << vectorOfPMini.at(i).getUsername() << "  : " << vectorOfPMini.at(i).getScore() << endl;
    }
}

void PlayerInGameCandy::reverseTurnInitial()
{
    this->reversedThisRoundInfo = make_pair(true, getCurrentTurn());
    reverse(turns.begin() + getCurrentTurn() + 1, turns.end());
}

void PlayerInGameCandy::resetRound()
{
    PlayerInGame::resetRound();
    if (reversedThisRoundInfo.first)
    {
        reverseTurnPost(reversedThisRoundInfo.second);
    }
    else
    {
        rotate(turns.begin(), turns.begin() + 1, turns.end());
    }
    reversedThisRoundInfo = make_pair(false, -1);
}

void PlayerInGameCandy::reverseTurnPost(int pivotIndex)
{
    reverse(turns.begin(), turns.begin() + pivotIndex);
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
        getPlayerAtTurn(i).redrawCard(deckGame);
    }
};

void PlayerInGameCandy::showPlayerExcept(vector<int> exceptedIndex)
{
    int numberOfPlayer = getNumberOfPlayer();
    int indexOfCurrentTurn = getIndexOfCurrentTurn();
    int numbering = 0;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        if (exceptedIndex.end() == find(exceptedIndex.begin(), exceptedIndex.end(), i))
        {
            cout << numbering + 1 << ". "
                 << "Player " << getNthPlayer(i).getUsername() << endl;
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
    PlayerCandy &playerTarget = getNthPlayer(index);
    playerSource.swapDeck(playerTarget);
};

void PlayerInGameCandy::swapCardOfPlayer(int sourceIndex, int targetIndex, bool firstLeft, bool secondLeft)
{
    PlayerCandy &playerSource = getNthPlayer(sourceIndex);
    PlayerCandy &playerTarget = getNthPlayer(targetIndex);
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
            swap(firstLeftCard, secondRightCard);
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
    rawIndex--;
    if (rawIndex < 0 || rawIndex >= getNumberOfPlayer() - exceptedIndexes.size())
    {
        OutOfBoundIndex e;
        throw e;
    }
    sort(exceptedIndexes.begin(), exceptedIndexes.end());
    auto exceptedIndexesIt = exceptedIndexes.begin();
    bool foundLimit = false;
    int resultIndex = rawIndex;
    int numberOfExceptedUnder = 0;
    int numberOfPlayer = getNumberOfPlayer();

    vector<int> allIndex;

    for (int i = 0; i < numberOfPlayer; i++)
    {
        allIndex.push_back(i);
    }

    int reversedEngineeredIndex = -1;
    for (int i = 0; i < numberOfPlayer && !foundLimit; i++)
    {
        if (exceptedIndexes.end() == find(exceptedIndexes.begin(), exceptedIndexes.end(), i))
        {
            reversedEngineeredIndex++;
        }
        foundLimit = reversedEngineeredIndex == rawIndex;
        if (foundLimit)
        {
            resultIndex = i;
        }
    }
    return resultIndex;
};

string PlayerInGameCandy::getWinner()
{
    long long limit = 4294967296;
    bool found = false;
    string winnerUsername;
    for (int i = 0; i < getNumberOfPlayer() && !found; i++)
    {
        long long score = getNthPlayer(i).getScore();
        if (score >= limit)
        {
            winnerUsername = (getNthPlayer(i).getUsername());
            found = true;
        }
    }
    return winnerUsername;
};

bool PlayerInGameCandy::winnerExist()
{
    long long limit = 4294967296;
    return players.end() != find_if(players.begin(), players.end(), [limit](PlayerCandy p) -> bool
                                    { return p.getScore() > limit; });
};

void PlayerInGameCandy::drawAbilityCardAll(DeckGame<AbilityCard> &deckAbility)
{
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        getPlayerAtTurn(i).drawAbility(deckAbility);
    }
};

void PlayerInGameCandy::drawColorCardAll(DeckGame<ColorCard> &deckColor)
{
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        getPlayerAtTurn(i).drawCard(deckColor, 2);
    }
};

bool PlayerInGameCandy::disablePlayerAbility(int index)
{
    bool succesful = getNthPlayer(index).getAbilityAvailable();
    getNthPlayer(index).disableAbility();
    return succesful;
}

bool PlayerInGameCandy::isAllAbilityDisable()
{
    int count = 0;
    for (int i = 0; i < getNumberOfPlayer(); i++)
    {
        if (!getNthPlayer(i).getAbilityAvailable())
        {
            count++;
        }
    }
    return count == 6;
}

bool PlayerInGameCandy::playerIndexInRange(int index)
{
    return index >= 0 && index < getNumberOfPlayer();
}

pair<PlayerCandy, Combination> PlayerInGameCandy::rewardHighestCombination(long long reward, DeckGame<ColorCard> &tableCard)
{

    int numberOfPlayer = getNumberOfPlayer();
    int indexOfHighest = 0;
    for (int i = 1; i < numberOfPlayer; i++)
    {
        if (getNthPlayer(i).higherCombinationWeight(getNthPlayer(indexOfHighest), tableCard))
        {
            indexOfHighest = i;
        }
    }
    PlayerCandy &highestPlayer = getNthPlayer(indexOfHighest);
    Deck<ColorCard> winningHand = highestPlayer.getHand();
    Deck<ColorCard> tableCardCopy(tableCard);
    Combination highestCombination(winningHand, tableCard);

    highestPlayer += reward;
    return make_pair(highestPlayer, highestCombination);
}

void PlayerInGameCandy::printTurnRemaining()
{
    vector<int> turnsCopy = this->turns;
    cout << "\033[1m\033[37m";
    for (auto i = turnsCopy.begin() + getIndexOfCurrentTurn(); i != turnsCopy.end(); ++i)
        cout << "p" << (*i) + 1 << " ";
    cout << "\033[0m" << endl;
}

void PlayerInGameCandy::printTurnNext()
{
    vector<int> turnsCopy = this->turns;
    cout << "\033[1m\033[37m";
    if (!reversedThisRoundInfo.first)
    {
        rotate(turnsCopy.begin(), turnsCopy.begin() + 1, turnsCopy.end());
    }
    else
    {
        reverse(turnsCopy.begin(), turnsCopy.begin() + getCurrentTurn());
        reverse(turnsCopy.begin() + getCurrentTurn(), turnsCopy.end());
    }
    for (auto i = turnsCopy.begin(); i != turnsCopy.end(); ++i)
        cout << "p" << (*i) + 1 << " ";
    cout << "\033[0m" << endl;
}
