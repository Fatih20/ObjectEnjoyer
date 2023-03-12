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
    // PlayerInGame(DeckGame<T> deckGame, int numberOfCards, int numberOfPlayer);

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
    T &getPlayerWithTurn();

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
     * @brief Get the current turn
     *
     * @return true
     * @return false
     */
    int getCurrentTurn();

    /**
     * @brief Get the index of the player with the current turn
     *
     * @return true
     * @return false
     */
    int getIndexOfCurrentTurn();

    /**
     * @brief Change the turn to the next person in line
     *
     */
    void nextTurn();

    /**
     * @brief Print all of the player's in the game
     *
     */
    virtual void showPlayer();

    /**
     * @brief Remove player with the gameID of removedID
     *
     * @param removedID
     */
    virtual void removePlayerOfID(int removedID) = 0;

    /**
     * @brief Set roundComplete to true
     *
     */
    void stopRound();

    virtual void remove(int index);

    /**
     * @brief Return whether the username exist in the object
     *
     * @param username
     * @return true
     * @return false
     */
    virtual bool usernameExist(string username) = 0;
};
// Kurang retake deck dan re-roll
