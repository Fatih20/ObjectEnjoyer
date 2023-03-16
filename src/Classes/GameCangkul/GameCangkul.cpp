#include "GameCangkul.hpp"

vector<string> commandOptionCangkul = {
    "play",     //play a card
    "cangkul",  //cangkul deckGame
    "ambil"     //take a card from deckTable
};

GameCangkul::GameCangkul() {
    DeckGame<ColorCard> deckGame(initializeDeckGame());
    deckGame.shuffle();

    this->deckGame = deckGame;
}

void GameCangkul::start() {
    string cmd;
    while(!isWinning()){
        cmd = GameCangkul::inputCommand();
        cout << cmd;
    }
}

bool GameCangkul::isWinning() {
//    return players.winnerExist();
    return false;
}

void GameCangkul::newGame() {

}

void GameCangkul::endOfGame() {

}

std::string GameCangkul::inputCommand() {
    string cmd;
    bool isValid = false;

    while(!isValid){
        try{
            cout << "> ";
            cin >> cmd;
            GameCangkul::isCommandValid(cmd);

            isValid = true;
        } catch(CangkulCommandInvalid& e) {
            cout << e.what() << endl;
        }
    }

    return cmd;
}

std::string GameCangkul::isCommandValid(std::string userCommand) {
    string temp = userCommand;

    //lower sentence
    transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);

    //check if command exists
    vector<string>::iterator it;
    it = find(commandOptionCangkul.begin(), commandOptionCangkul.end(), userCommand);

    if(it != commandOptionCangkul.end()){
        return userCommand; //?
    } else {
        throw CangkulCommandInvalid(temp);
    }
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