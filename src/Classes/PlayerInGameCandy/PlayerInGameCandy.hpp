#include "../PlayerInGame/PlayerInGame.hpp"
#include "Classes/PlayerCandy/PlayerCandy.hpp"

#include <iostream>

using namespace std;

class PlayerInGameCandy : public PlayerInGame<PlayerCandy>
{
private:
    int correctedIndex(int rawIndex);

public:
    /**
     * @brief Construct a new Player In Game Candy object
     *
     * @param numberOfPlayer
     * @param currentTurn starts at 0
     */
    PlayerInGameCandy(DeckGame<ColorCard> deckGame, int numberOfPlayer);

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

    void createAndAddPlayer(int gameID);

    bool usernameExist(string username);

    /**
     * @brief Show player except for the current player
     */
    void showPlayerExceptCurrent();

    /**
     * @brief Remove player with the ID of removedID
     *
     * @param removedID
     */
    void removePlayerOfID(int removedID);

    /**
     * @brief Redraw the card for the player's currently in turn
     *
     * @param deckGame
     */
    void redrawCardForCurrentPlayer(DeckGame<ColorCard> &deckGame);
};