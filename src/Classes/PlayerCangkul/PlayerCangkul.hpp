#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "../Player/Player.hpp"

class PlayerCangkul : public Player<ColorCard> {
    private:
        static int num_player;

    public:
        PlayerCangkul();
};

#endif