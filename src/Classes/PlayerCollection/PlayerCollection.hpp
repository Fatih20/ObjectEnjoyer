#include <vector>
#include "../Player/Player.hpp"

class PlayerCollection
{
private:
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
     * @brief Print the leaderboard of players in the collection
     *
     */
    void showLeaderboard();
};