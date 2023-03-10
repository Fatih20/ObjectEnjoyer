#include "PlayerCollection.hpp"
#include <iostream>

using namespace std;

PlayerCollection::PlayerCollection(int numberOfPlayer)
{
    vector<Player> players(0);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        Player p(i + 1);
        bool usernameUnique = !usernameExist(p.getUsername());
        while (!usernameUnique)
        {
            p.setValidUsername();
            usernameUnique = !usernameExist(p.getUsername());
        }
        players.push_back(p);
    }
};

int PlayerCollection::getNumberOfPlayer()
{
    return players.size();
}

void PlayerCollection::addPlayer(Player &addedPlayer)
{
    players.push_back(addedPlayer);
}

void PlayerCollection::operator<<(Player &addedPlayer)
{
    addPlayer(addedPlayer);
}

void PlayerCollection::remove(int index)
{
    players.erase(players.begin() + (index - 1));
}

void PlayerCollection::operator-=(int index)
{
    remove(index);
}

bool PlayerCollection::usernameExist(string username)
{
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = players.at(i).getUsername() == username;
    }
    return found;
}