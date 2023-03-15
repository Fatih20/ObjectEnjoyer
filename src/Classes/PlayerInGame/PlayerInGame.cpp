#include "PlayerInGame.hpp"
#include "Classes/PlayerInGameException/PlayerInGameException.hpp"
#include "Classes/PlayerCandy/PlayerCandy.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
PlayerInGame<T>::PlayerInGame() : PlayerInGame<T>(0){};

template <typename T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer) : PlayerCollection<T>(numberOfPlayer)
{
    vector<int> turnsCreated;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        turnsCreated.push_back(i);
    }
    this->turns = turnsCreated;
    currentTurn = 0;
    roundComplete = false;

    // cout << "Turns size after PIG construction : " << turns.size() << endl;
};

template <typename T>
PlayerInGame<T>::PlayerInGame(const PlayerInGame &playerInGame) : PlayerCollection<T>(playerInGame)
{
    this->turns = playerInGame.turns;
    this->currentTurn = playerInGame.currentTurn;
    this->roundComplete = playerInGame.roundComplete;
};

// template <typename T>
// PlayerInGame<T>::PlayerInGame(DeckGame<T> deckGame, int numberOfCards, int numberOfPlayer) : PlayerInGame<T>(numberOfPlayer)
// {
//     for (int i = 0; i < numberOfPlayer; i++)
//     {
//         this->players.at(turns.at(i)).drawCard(deckGame, numberOfCards);
//     }
// };

template <typename T>
PlayerInGame<T>::PlayerInGame(int numberOfPlayer, int currentTurn) : PlayerInGame<T>(numberOfPlayer)
{
    this->currentTurn = currentTurn;
};

template <typename T>
void PlayerInGame<T>::setTurn(int newTurn)
{
    int numberOfPlayer = this->getNumberOfPlayer();
    currentTurn = (((newTurn) % numberOfPlayer) + numberOfPlayer) % numberOfPlayer;
};
template <typename T>
void PlayerInGame<T>::reverseTurn()
{
    reverse(turns.begin(), turns.end());
};
template <typename T>
int PlayerInGame<T>::getCurrentTurn()
{
    return currentTurn;
};

template <typename T>
vector<int> PlayerInGame<T>::getTurns()
{
    return turns;
};

template <typename T>
int PlayerInGame<T>::getIndexOfCurrentTurn()
{
    return turns.at(currentTurn);
}

// template <typename T>
// void PlayerInGame<T>::removePlayerOfID(int removedID)
// {
//     // To do : Erase from turn list as well
//     for (int i = 0; i < this->players.size(); i++)
//     {
//         if (this->players.at(i).getGameID() == removedID)
//         {
//             this->players.erase(this->players.begin() + i);
//         }
//     };
// };

// template <typename T>

template <typename T>
T &PlayerInGame<T>::getPlayerWithTurn()
{
    return this->players.at(turns.at(currentTurn));
};

template <typename T>
void PlayerInGame<T>::nextTurn()
{

    // Only increment current turn when the turn is still in range and the round isn't completed
    currentTurn += currentTurn < this->getNumberOfPlayer() && !roundComplete ? 1 : 0;

    // Set the roundComplete to true once the last player is done
    roundComplete = currentTurn >= this->getNumberOfPlayer();
};

template <typename T>
bool PlayerInGame<T>::getIsRoundComplete()
{
    return roundComplete;
};

template <typename T>
void PlayerInGame<T>::resetRound()
{
    roundComplete = false;
    currentTurn = 0;
};

template <typename T>
void PlayerInGame<T>::stopRound()
{
    roundComplete = true;
};

template <typename T>
void PlayerInGame<T>::showPlayer()
{
    for (int i = 0; i < this->players.size(); i++)
    {
        cout << i + 1 << ". " << this->players.at(i) << endl;
    }
};

// template <typename T, typename Func>
// void PlayerInGame<T>::showPlayerIf(const Func &f)
// {
//     bool print = true;
//     int index = 0;
//     for (int i = 0; i < this->players.size(); i++)
//     {
//         if (this->players.at(i).getGameID() != unprintedID)
//         {
//             cout << index + 1 << ". " << this->players.at(i).getUsername() << endl;
//             index++;
//         }
//     }
// };

template <typename T>
Player<T> &PlayerInGame<T>::getNthPlayer(int index)
{
    return players.at(index);
}

template <typename T>
void PlayerInGame<T>::remove(int index)
{
    remove_if(turns.begin(), turns.end(), [index](int element) -> bool
              { return index == element; });

    PlayerCollection<T>::remove(index);
}

// template <typename T>
// void PlayerInGame<T>::showPlayerExcept(int unprintedID)
// {
//     bool print = true;
//     int index = 0;
//     for (int i = 0; i < this->players.size(); i++)
//     {
//         if (this->players.at(i).getGameID() != unprintedID)
//         {
//             cout << index + 1 << ". " << this->players.at(i).getUsername() << endl;
//             index++;
//         }
//     }
// };

// template <typename T>
// void PlayerInGame<T>::redrawCardForNthPlayer(DeckGame<T> &deckGame, int n)
// {
//     this->players.at(n).redrawCard(deckGame);
// };

// template <typename T>
// void PlayerInGame<T>::redrawCardForCurrentPlayer(DeckGame<T> &deckGame)
// {
//     redrawCardForNthPlayer(deckGame, getCurrentTurn());
// };

template class PlayerInGame<Player<ColorCard>>;
template class PlayerInGame<PlayerCandy>;
