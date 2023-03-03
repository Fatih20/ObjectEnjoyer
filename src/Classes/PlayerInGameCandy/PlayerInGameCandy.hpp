#include "../PlayerInGame/PlayerInGame.hpp"
#include <iostream>

using namespace std;

class PlayerInGameCandy : public PlayerInGame
{
public:
    /**
     * @brief Construct a new Player In Game Candy object
     *
     * @param numberOfPlayer
     * @param currentTurn starts at 1
     */
    PlayerInGameCandy(int numberOfPlayer, int currentTurn);
    /**
     * @brief Print the leaderboard of players in the collection
     *
     */
    void showLeaderboard();

    /**
     * @brief Reverse the turn direction of the game according to the candy law
     *
     */
    void reverseTurn();
};