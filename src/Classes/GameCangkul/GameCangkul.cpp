#include "GameCangkul.hpp"

GameCangkul::GameCangkul() {
    DeckGame<ColorCard> deckGame(initializeDeckGame());
    deckGame.shuffle();
    this->drawPile = deckGame;
}

void GameCangkul::start() {
//    this->deckGame =
//
//    this->deckTable.clear();
    cout << "Game Cangkul" << endl;
}

bool GameCangkul::isWinning() {
    return true;
}

void GameCangkul::newGame() {

}

void GameCangkul::endOfGame() {

}

std::string GameCangkul::inputCommand() {
    return "oke\n";
}

std::string GameCangkul::isCommandValid(std::string command) {
    return "oke\n";
}

void GameCangkul::splashScreen() {

}

int GameCangkul::inputOption(int opt) {
    return 0;
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