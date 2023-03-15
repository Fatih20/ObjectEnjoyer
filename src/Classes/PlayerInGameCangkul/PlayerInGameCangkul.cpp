#include "PlayerInGameCangkul.hpp"

PlayerInGameCangkul::PlayerInGameCangkul() : PlayerInGame<PlayerCangkul>() {
    PlayerCangkul p1;
    PlayerCangkul p2;
    this->addPlayer(p1);
    this->addPlayer(p2);
}

std::string PlayerInGameCangkul::getWinner() {
    if (this->winnerExist()) {
        for(int i = 0; i < this->players.size(); i++) {
            if (this->players[i].isWinner()) {
                return this->players[i].getUsername();
            }
        }
    } else {
        return "No Winner";
    }
}

bool PlayerInGameCangkul::winnerExist(){
    for(int i = 0; i < this->players.size(); i++) {
        if (this->players[i].isWinner()) {
            return true;
        }
    }
}