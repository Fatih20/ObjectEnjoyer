#include <vector>
#include "../Player/Player.hpp"

class PlayerCollection
{
protected:
    vector<Player> players;

public:
    PlayerCollection(int numberOfPlayer);
    /**
     * @brief Return the number of player in this collection
     *
     */
    int getNumberOfPlayer();

    /**
     * @brief Add addedPlayer into the collection as the last player
     *
     * @param addedPlayer
     */
    void operator<<(Player &addedPlayer);

    /**
     * @brief Remove a player from the collection
     *
     * @param index starts at one
     */
    void remove(int index);

    /**
     * @brief Remove a player from the collection
     *
     * @param index starts at one
     */

    void operator-=(int index);
};