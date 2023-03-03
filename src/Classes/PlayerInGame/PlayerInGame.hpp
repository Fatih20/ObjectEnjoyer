#include "../PlayerCollection/PlayerCollection.hpp"

class PlayerInGame : public PlayerCollection
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
     * @param numberOfPlayer the number of player in it
     */
    PlayerInGame(int numberOfPlayer);

    /**
     * @brief Construct a new Player In Game object
     *
     * @param numberOfPlayer
     * @param currentTurn starts at 1
     */
    PlayerInGame(int numberOfPlayer, int currentTurn);

    /**
     * @brief Return the player that currently has the turn
     *
     */
    Player &getPlayerWithTurn();

    /**
     * @brief Return the nth player that currently has the turn
     *
     */
    int getNthPlayerWithTurn();

    /**
     * @brief Move to the turn to the next player
     *
     */
    void nextTurn();

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
    void stopRound();
};