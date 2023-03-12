#include "../PlayerInGame/PlayerInGame.hpp"
#include "Classes/PlayerCandy/PlayerCandy.hpp"

#include <iostream>

using namespace std;

class PlayerInGameCandy : public PlayerInGame<PlayerCandy>
{
private:
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
     * @brief Show players except for the one found in the exceptedIndex
     *
     * @param exceptedIndex
     */
    void showPlayerExcept(vector<int> exceptedIndex);

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

    /**
     * @brief Swap the deck of the current player with another player given by index
     *
     * @param rawTargetIndex
     */
    void swapDeckOfCurrentWith(int rawTargetIndex);

    /**
     * @brief Swap the deck between the player of the given index
     *
     * @param rawSourceIndex
     * @param rawTargetIndex
     */
    void swapDeckOfPlayer(int rawSourceIndex, int rawTargetIndex);

    /**
     * @brief Correct the index of the player with the rawIndex excepted
     *
     * @param rawIndex
     * @return int
     */
    int correctedIndexCurrent(int rawIndex);

    /**
     * @brief Correct the index of the player with the rawIndex excepted
     *
     * @param rawIndex
     * @param exceptedIndexes
     * @return int
     */
    int correctedIndexCustom(int rawIndex, vector<int> exceptedIndexes);
};