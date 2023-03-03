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
     * @brief Reverse the turn of the game for players after the one currently holding the turn
     *
     */
    void reverseTurn();

    /**
     * @brief Reset roundComplete to true and rearrange the turn according to the rules
     *
     */
    void resetRound();
};