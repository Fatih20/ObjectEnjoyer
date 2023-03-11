#include <vector>
#include "../Player/Player.hpp"

template <typename T>
class PlayerCollection
{
protected:
    vector<Player<T>> players;

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
    void operator<<(Player<T> &addedPlayer);

    /**
     * @brief Add addedPlayer into the collection as the last player
     *
     * @param addedPlayer
     */
    void addPlayer(Player<T> &addedPlayer);

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

    bool usernameExist(string username);
};