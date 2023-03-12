#ifndef _PLAYER_CANDY_HPP
#define _PLAYER_CANDY_HPP

#include "Classes/Player/Player.hpp"
#include "Classes/ColorCard/ColorCard.hpp"

class PlayerCandy : public Player<ColorCard>
{
public:
    /**
     * @brief Construct a new Player Candy object with the given gameID
     *
     * @param gameID
     */
    PlayerCandy(int gameID);

    /**
     * @brief Construct a new Player Candy object with 0 as gameID
     *
     */
    PlayerCandy();
};

#endif