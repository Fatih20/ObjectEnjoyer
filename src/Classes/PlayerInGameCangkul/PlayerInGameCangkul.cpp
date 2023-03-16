#include "PlayerInGameCangkul.hpp"

PlayerInGameCangkul::PlayerInGameCangkul() : PlayerInGame<PlayerCangkul>(0) {
}

PlayerInGameCangkul::PlayerInGameCangkul(int playerNum) :PlayerInGame<PlayerCangkul>(playerNum) {
    for(int i = 0; i < playerNum; i++){
        createAndAddPlayer(i + 1);
    }
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
    int numberOfNonWinner = 0;

    for(int i = 0; i < this->players.size(); i++) {
        if (!this->players[i].isWinner()) {
            numberOfNonWinner++;
        }
    }

    return numberOfNonWinner == 1;
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

void PlayerInGameCangkul::createAndAddPlayer(int gameID) {
    PlayerCangkul p(gameID);
    while (PlayerInGameCangkul::usernameExist(p.getUsername()))
    {
        cout << "Username itu sudah dipakai! Pilih yang lain." << endl;
        p.setValidUsername();
    }
    players.emplace_back(p);
}