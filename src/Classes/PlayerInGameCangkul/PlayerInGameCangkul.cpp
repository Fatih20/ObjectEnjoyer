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
            return true; // we need to change this if we're going to make it >2 players in the future
        }
    }
}

void PlayerInGameCangkul::removePlayerOfID(int removedID) {
    for(int i = 0; i < this->players.size(); i++) {
        if (this->players[i].getGameID() == removedID) {
            this->players.erase(this->players.begin() + i);
        }
    }
}

bool PlayerInGameCangkul::usernameExist(std::string username) {
    for(int i = 0; i < this->players.size(); i++) {
        if (this->players[i].getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool PlayerInGameCangkul::usernameExist(std::string username, int gameID) {
    for(int i = 0; i < this->players.size(); i++) {
        if (this->players[i].getUsername() == username && this->players[i].getGameID() == gameID) {
            return true;
        }
    }
    return false;
}