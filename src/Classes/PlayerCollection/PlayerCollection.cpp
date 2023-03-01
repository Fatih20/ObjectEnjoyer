#include "PlayerCollection.hpp"
#include <iostream>

using namespace std;

PlayerCollection::PlayerCollection(int numberOfPlayer)
{
    vector<Player> players(0);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        Player p;
        players.push_back(p);
    }
};

int PlayerCollection::getNumberOfPlayer()
{
    return players.size();
}

void PlayerCollection::operator<<(Player &addedPlayer)
{
    players.push_back(addedPlayer);
}

void PlayerCollection::remove(int index)
{
    players.erase(players.begin() + (index - 1));
}

void PlayerCollection::operator-=(int index)
{
    remove(index);
}