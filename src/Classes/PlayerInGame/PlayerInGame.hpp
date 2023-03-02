#include "../PlayerCollection/PlayerCollection.hpp"

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
};