#include "../PlayerCollection/PlayerCollection.hpp"
#include "Classes/DeckGame/DeckGame.hpp"

template <typename T>
class PlayerInGame : public PlayerCollection<T>
{

protected:
    vector<int> turns;
    int currentTurn;
    bool roundComplete;

protected:
    /**
     * @brief Set the turn of the object
     *
     * @param newTurn starts at one
     */
    void setTurn(int newTurn);

    /**
     * @brief Reverse the turn direction of the player
     *
     */
    virtual void reverseTurn();

public:
    /**
     * @brief Construct a new Player In Game object
     *
     */
    PlayerInGame();

    /**
     * @brief Construct a new Player In Game object
     *
     * @param deckGame the deck for the player to draw from
     * @param numberOfCards the number of cards given to each player
     * @param numberOfPlayer the number of player in the game
     */
    PlayerInGame(DeckGame<T> deckGame, int numberOfCards, int numberOfPlayer);

    /**
     * @brief Construct a new Player In Game object
     *
     * @param numberOfPlayer the number of player in it
     */
    PlayerInGame(int numberOfPlayer);

    /**
     * @brief Construct a new Player In Game object
     *
     * @param numberOfPlayer
     * @param currentTurn starts at 0
     */
    PlayerInGame(int numberOfPlayer, int currentTurn);

    /**
     * @brief Return the player that currently has the turn
     *
     */
    Player<T> &getPlayerWithTurn();

    /**
     * @brief Make the nth player redraw their card
     *
     * @param deckGame the deck from which the player's draw their card
     * @param n the turn of the player's to redraw
     */
    void redrawCardForNthPlayer(DeckGame<T> &deckGame, int n);

    /**
     * @brief Redraw the card for the player's currently in turn
     *
     * @param deckGame
     */
    void redrawCardForCurrentPlayer(DeckGame<T> &deckGame);

    /**
     * @brief Whether the round is complete or not
     *
     * @return true
     * @return false
     */
    bool getIsRoundComplete();

    /**
     * @brief Reset roundComplete to false
     *
     */
    virtual void resetRound();

    /**
     * @brief Change roundComplete to true
     *
     */
    bool getCurrentTurn();

    /**
     * @brief Change the turn to the next person in line
     *
     */
    void nextTurn();

    /**
     * @brief Print all of the player's in the game
     *
     */
    void showPlayer();

    /**
     * @brief Print all of the player's except one with the gameID of unprintedID
     *
     * @param unprintedID
     */
    void showPlayerExcept(int unprintedID);

    /**
     * @brief Remove player with the gameID of removedID
     *
     * @param removedID
     */
    void removePlayerOfID(int removedID);

    // Kurang retake deck dan re-roll
    void stopRound();
};
// Kurang retake deck dan re-roll
