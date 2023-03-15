#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "../Player/Player.hpp"

class PlayerCangkul : public Player<ColorCard> {
    private:
        static int num_player;

    public:
        PlayerCangkul();

        bool isWinner();

        void printCards();

        void playCard(int index);
};

#endif