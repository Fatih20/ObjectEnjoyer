#include "PlayerCollection.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include <iostream>

using namespace std;
template <typename T>
PlayerCollection<T>::PlayerCollection(int numberOfPlayer)
{
    vector<Player<T>> players(0);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        Player<T> p(i + 1);
        bool usernameUnique = !usernameExist(p.getUsername());
        while (!usernameUnique)
        {
            cout << "Username already exists!" << endl;
            p.setValidUsername();
            usernameUnique = !usernameExist(p.getUsername());
        }
        players.push_back(p);
    }
};

template <typename T>
int PlayerCollection<T>::getNumberOfPlayer()
{
    return players.size();
}
template <typename T>
void PlayerCollection<T>::addPlayer(Player<T> &addedPlayer)
{
    players.push_back(addedPlayer);
}
template <typename T>
void PlayerCollection<T>::operator<<(Player<T> &addedPlayer)
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

template <typename T>
bool PlayerCollection<T>::usernameExist(string username)
{
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = players.at(i).getUsername() == username;
    }
    return found;
}

template class PlayerCollection<ColorCard>;