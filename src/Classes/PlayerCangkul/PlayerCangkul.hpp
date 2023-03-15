#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "../Player/Player.hpp"

class PlayerCangkul : public Player<ColorCard> {
private:
    bool hasWon; // to mark deck empty? may be useful may be erased in the future

public:
    PlayerCangkul();
    PlayerCangkul(int id);
    PlayerCangkul(const PlayerCangkul& p);


};

#endif