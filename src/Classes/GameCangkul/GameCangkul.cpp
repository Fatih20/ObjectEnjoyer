#include "GameCangkul.hpp"

GameCangkul::GameCangkul() {

}

void GameCangkul::start() {
//    this->deckGame =
//
//    this->deckTable.clear();
}

bool GameCangkul::isWinning() {

}

void GameCangkul::newGame() {

}

void GameCangkul::endOfGame() {

}

std::string GameCangkul::inputCommand() {

}

std::string GameCangkul::isCommandValid(std::string command) {

}

void GameCangkul::splashScreen() {

}

int GameCangkul::inputOption(int opt) {

}

std::vector<ColorCard> GameCangkul::initializeDeckGame() {
    std::vector<ColorCard> deckGame;
    Color col;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++) {
            switch(i){
                case 0 :
                    col = GREEN;
                    break;
                case 1:
                    col = BLUE;
                    break;
                case 2:
                    col = YELLOW;
                    break;
                case 3:
                    col = RED;
                    break;

            }
            ColorCard cc(j, col);
            deckGame.push_back(cc);
        }
    }

    return deckGame;
}