#include "PlayerInGame.hpp"
#include "../PlayerInGameException/PlayerInGameException.hpp"
#include "../PlayerCandy/PlayerCandy.hpp"
#include "../PlayerCangkul/PlayerCangkul.hpp"
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
void PlayerInGame<T>::setTurnsHead(int offset) {
    vector<int> newTurns;
    for (int i = offset; i < this->getNumberOfPlayer(); i++)
    {
        newTurns.push_back(this->turns[i]);
    }
    for(int i = 0; i < offset; i++){
        newTurns.push_back(this->turns[i]);
    }

    this->turns = newTurns;

    currentTurn = 0;
    roundComplete = false;
}

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
    return getPlayerAtTurn(currentTurn);
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
        cout << i + 1 << ". " << this->getNthPlayer(i) << endl;
    }
};

template <typename T>
void PlayerInGame<T>::remove(int index)
{
    remove_if(turns.begin(), turns.end(), [index](int element) -> bool
              { return index == element; });

    PlayerCollection<T>::remove(index);
}

template <typename T>
T &PlayerInGame<T>::getPlayerAtTurn(int turn)
{
    return this->getNthPlayer(turns.at(turn));
};



template class PlayerInGame<Player<ColorCard>>;
template class PlayerInGame<PlayerCandy>;
template class PlayerInGame<PlayerCangkul>;

