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
     * @param turn
     * @param leftIsDirection
     */
    PlayerInGameCandy(int numberOfPlayer, int turn, bool directionIsLeft);
    /**
     * @brief Print the leaderboard of players in the collection
     *
     */
    void showLeaderboard();

    /**
     * @brief Reverse the turn direction of the game
     *
     */
    void reverse();
};