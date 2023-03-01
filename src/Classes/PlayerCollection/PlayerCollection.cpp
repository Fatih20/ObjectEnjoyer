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

void PlayerCollection::showLeaderboard()
{
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ".";
        players.at(i).getScore();
    }
}