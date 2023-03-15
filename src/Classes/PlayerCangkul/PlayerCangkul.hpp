#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "Player/Player.hpp"

class PlayerCangkul : public Player<ColorCard> {
public:
    PlayerCangkul();
    PlayerCangkul(int id);
    PlayerCangkul(const PlayerCangkul& p);


};

#endif