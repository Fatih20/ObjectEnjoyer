#include "GameCangkul.hpp"

vector<string> commandOptionCangkul = {
    "play",     //play a card
    "cangkul",  //cangkul deckGame
    "ambil",    //take a card from deckTable
    "gamestat", //show current game stat
    "mycard",   //show current card on hands
    "help"      //help options
};

GameCangkul::GameCangkul() {
    DeckGame<ColorCard> deckGame(initializeDeckGame());
    deckGame.shuffle();

    PlayerInGameCangkul pIGC(2);
    this->players = pIGC;

    this->deckGame = deckGame;
    this->gameStarted = false; // may even be unneeded
}

void GameCangkul::start() {
    string cmd;

    GameCangkul::newGame();
    while(!isWinning() && gameStarted){
        cout << "Round " << GameCangkul::getRoundNumber() << endl;
        while(!GameCangkul::isRoundOver()){

            cout << "\033[1m\033[37m"
                 << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn"
                 << "\033[0m" << endl;

            cmd = GameCangkul::inputCommand();

            // loop while called command is command that wont progress the game
            while(!GameCangkul::playerAction(cmd)){
                cmd = GameCangkul::inputCommand();
            }

            players.nextTurn();
        }
        GameCangkul::nextRound();
        players.resetRound();
    }
}

bool GameCangkul::isWinning() {
//    return players.winnerExist();
    return false;
}

void GameCangkul::newGame() {
    //NOTE : game candy doesnt init player deck from this method
    for(int i = 0; i < players.getNumberOfPlayer(); i++){
        players.getNthPlayer(i).drawCard(this->deckGame, 7);
    }

    this->gameStarted = true;
}

void GameCangkul::endOfGame() {

    this->gameStarted = false;
}

std::string GameCangkul::inputCommand() {
    string cmd;
    bool isValid = false;

    while(!isValid){
        try{
            cout << "> ";
            cin >> cmd;
            cmd = GameCangkul::isCommandValid(cmd);

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

//int GameCangkul::inputOption(int opt) {
//    return 0;
//}

bool GameCangkul::playerAction(string cmd) {

    if(cmd == "play"){
        cout << "playing a card" << endl;
        //bisa return false
//        return true;

        return playCard();
    } else if (cmd == "cangkul") {
        cout << "player turn draw from deck";
        //bisa return false
        return true;
    } else if (cmd == "ambil") {
        cout << "cek deck apakah kosong and can";

        //bisa return false
        return true;
    } else if (cmd == "gamestat") {
        cout << "show gamestat";

        return false;
    } else if (cmd == "mycard") {
        cout << players.getNumberOfPlayer() << endl;
//        cout << players.getPlayerWithTurn().getGameID() << endl;
        players.getPlayerWithTurn().printCard(true);

        return false;
    } else if (cmd == "help") {
        cout << "show help messages"; //TODO

        return false;
    }

    return false;
}

int GameCangkul::getRoundNumber() {
    return this->round + 1; // NOTE: be careful of this +1, useful on print
}

bool GameCangkul::isRoundOver(){
    return players.getIsRoundComplete();
}

void GameCangkul::nextRound() {
    this->round++;
}

void GameCangkul::displayGameStat()
{
    cout << "\033[1m\033[35m"
         << "---------------------------------" << endl;
    cout << "           GAME STATUS" << endl;
    cout << "---------------------------------"
         << "\033[0m" << endl;
    cout << "\033[1m\033[37m"
         << "Turns: " << endl;
    vector<int> turnsVec = players.getTurns();
    for (auto i = turnsVec.begin(); i != turnsVec.end(); ++i)
    {
        if (*i == players.getIndexOfCurrentTurn())
            cout << "\033[1m\033[32m"
                 << "p" << (*i) + 1 << " "
                 << "\033[0m";
        else
            cout << "p" << (*i) + 1 << " ";
    }
    cout << endl;
    for (auto i = turnsVec.begin(); i != turnsVec.end(); ++i)
    {
        if (*i == players.getIndexOfCurrentTurn())
            cout << "\033[1m\033[32m"
                 << "^   "
                 << "\033[0m";
        else
            cout << "   ";
    }
    cout << endl;

    GameCangkul::printTableCard();
}

void GameCangkul::printTableCard()
{
    cout << "\033[1m\033[37m"
         << "Table Card: "
         << "\033[0m" << endl;
    cout << "|  ";
    vector<ColorCard> tableVec = GameCangkul::deckTable.getDeck();
    for (auto i = tableVec.begin(); i != tableVec.end(); ++i)
    {
        cout << *i;
    }
    cout << endl;
}

bool GameCangkul::playCard() {
    bool finished = false;
    int count;

    cout << "Pilih kartu yang akan dimainkan : ";

    while(!finished){
        count = 0;

        players.getPlayerWithTurn().resetPlayableDeck();

        if(GameCangkul::deckTable.getNumberOfCards() != 0){
            players.getPlayerWithTurn().updatePlayableDeck(deckTable.getDeck()[0].getColor());
        } else {
            players.getPlayerWithTurn().updatePlayableDeck();
        }

        players.getPlayerWithTurn().printPlayableCard();

        count += players.getPlayerWithTurn().getNumberOfPlayableCard();

        int choice = Game::inputOption(count) - 1; // -1 since its an index



        finished = true;
    }


    return false;
}



std::vector<ColorCard> GameCangkul::initializeDeckGame() {
    std::vector<ColorCard> deckGame;
    Color col;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++) {
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