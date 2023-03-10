#include "../PlayerCollection/PlayerCollection.hpp"

template <class T>
class PlayerInGame : public PlayerCollection
{

private:
    int turn;
    bool directionIsLeft;

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
    void reverseTurn();

public:
    /**
     * @brief Construct a new Player In Game object
     *
     */
    PlayerInGame();

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
     * @param turn
     * @param directionLeft
     */
    PlayerInGame(int numberOfPlayer, int turn, int directionIsLeft);

    /**
     * @brief Return whether the direction of the turn is to the left
     *
     */
    bool getTurn();

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
};

// Kurang retake deck dan re-roll