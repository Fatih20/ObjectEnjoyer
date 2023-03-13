#include "PlayerCollection.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include "Classes/PlayerCandy/PlayerCandy.hpp"
#include <iostream>

using namespace std;
template <typename T>
PlayerCollection<T>::PlayerCollection() : PlayerCollection<T>(5){};

template <typename T>
PlayerCollection<T>::PlayerCollection(int numberOfPlayer)
{
    vector<T> players(0);
};

template <typename T>
PlayerCollection<T>::PlayerCollection(const PlayerCollection &pC)
{
    this->players = pC.players;
};

template <typename T>
int PlayerCollection<T>::getNumberOfPlayer()
{
    return players.size();
}
template <typename T>
void PlayerCollection<T>::addPlayer(T &addedPlayer)
{
    players.push_back(addedPlayer);
}
template <typename T>
void PlayerCollection<T>::operator<<(T &addedPlayer)
{
    addPlayer(addedPlayer);
}

template <typename T>
void PlayerCollection<T>::remove(int index)
{
    players.erase(players.begin() + (index - 1));
}

template <typename T>
void PlayerCollection<T>::operator-=(int index)
{
    remove(index);
}

template class PlayerCollection<Player<ColorCard>>;
template class PlayerCollection<PlayerCandy>;