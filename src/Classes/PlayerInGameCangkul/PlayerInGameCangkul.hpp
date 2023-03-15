#ifndef _PLAYERINGAME_CANGKUL_HPP_
#define _PLAYERINGAME_CANGKUL_HPP_

#include "../PlayerInGame/PlayerInGame.hpp"
#include "../PlayerCangkul/PlayerCangkul.hpp"

using namespace std;

class PlayerInGameCangkul : public PlayerInGame<PlayerCangkul> {
public:
    PlayerInGameCangkul();

    std::string getWinner();

    bool winnerExist();

};

#endif