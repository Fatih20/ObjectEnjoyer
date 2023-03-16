#include "GameCangkul.hpp"

vector<string> commandOptionCangkul = {
    "play",     //play a card
    "cangkul",  //cangkul deckGame
    "ambil",    //take a card from deckTable
    "gamestat", //show current game stat
    "mycard",   //show current card on hands
    "help"      //help options
};

void GameCangkul::displayHelp(){
    cout << "AVAILABLE COMMANDS\n";
    cout << "1. play        - play a card\n";
    cout << "2. cangkul     - take a card from the deck\n";
    cout << "3. ambil       - take a card from the table cards\n";
    cout << "4. gamestat    - show current game stat\n";
    cout << "5. mycard      - show your current hand\n";
    cout << "6. help        - show list of available commands\n";
}

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

        players.setTurnsHead(GameCangkul::getRoundWinnerIndex());

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
    cout << "MARI KITA MULAI\n";
    for(int i = 0; i < players.getNumberOfPlayer(); i++){
        players.getNthPlayer(i).drawCard(this->deckGame, 7);
    }

    this->gameStarted = true;
}

void GameCangkul::endOfGame() {
    cout << "GAME TAMAT YAH GES YAH\n";
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

bool GameCangkul::playerAction(string cmd) {

    if(cmd == "play"){
        cout << "playing a card" << endl;
        //bisa return false
//        return true;

        return playCard();
    } else if (cmd == "cangkul") {
        return GameCangkul::cangkulCard();
    } else if (cmd == "ambil") {
        cout << "cek deck apakah kosong and can";

        //bisa return false
        return true;
    } else if (cmd == "gamestat") {
        GameCangkul::displayGameStat();

        return false;
    } else if (cmd == "mycard") {
        GameCangkul::displayMyCard();

        return false;
    } else if (cmd == "help") {
        GameCangkul::displayHelp();

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

void GameCangkul::displayMyCard(){
    GameCangkul::players.getPlayerWithTurn().resetPlayableDeck();

    players.getPlayerWithTurn().printCard(true);
}

void GameCangkul::displayGameStat()
{
    GameCangkul::players.getPlayerWithTurn().resetPlayableDeck();

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
        ColorCard cardToPlay;

        players.getPlayerWithTurn().resetPlayableDeck();

        if(GameCangkul::deckTable.getNumberOfCards() != 0){
            players.getPlayerWithTurn().updatePlayableDeck(GameCangkul::getTableColor());
        } else {
            players.getPlayerWithTurn().updatePlayableDeck();
        }

        players.getPlayerWithTurn().printPlayableCard();

        count += players.getPlayerWithTurn().getNumberOfPlayableCard();

        if(players.getPlayerWithTurn().getNumberOfPlayableCard() != 0){
            int choice = Game::inputOption(count) - 1; // -1 since its an index

            cardToPlay = players.getPlayerWithTurn().ejectPlayableDeck(choice);
            GameCangkul::deckTable << cardToPlay;

            cout << "Memainkan kartu : " << cardToPlay;
        } else {
            players.getPlayerWithTurn().resetPlayableDeck();

            cout << "Gagal memainkan kartu, lakukan cangkul atau ambil" << endl;

            return false;
        }

        finished = true;
    }

    players.getPlayerWithTurn().resetPlayableDeck();

    return true;
}

bool GameCangkul::ambilCard(){

}

bool GameCangkul::cangkulCard() {
    if(GameCangkul::players.getPlayerWithTurn().getNumberOfPlayableCard() != 0){
        cout << "Masih ada kartu yang bisa dimainkan! tidak bisa mencangkul." << endl;

        return false;
    }

    ColorCard cangkuledCard = this->deckGame.ejectCard();

    cout << "Mendapatkan kartu " << cangkuledCard << endl;

    players.getPlayerWithTurn().addCard(cangkuledCard);

    return true;
}

Color GameCangkul::getTableColor() {
    if(GameCangkul::deckTable.getNumberOfCards() == 0){
        throw EmptyDeckException();
    }

    return GameCangkul::deckTable.getDeck()[0].getColor();
}

int GameCangkul::getRoundWinnerIndex() {
    int highestNumber = 0;
    int highestIndex = 0;

    for(int i = 0; i < this->deckTable.getNumberOfCards(); i++){
        if (highestNumber < this->deckTable.getDeck()[i].getNumber()){
            highestNumber = this->deckTable.getDeck()[i].getNumber();
            highestIndex = i;
        }
    }

    vector<ColorCard> emptyDeck;
    this->deckTable.setDeck(emptyDeck); // TODO : make this empty()

    cout << "Pemenang adalah " << players.getPlayerAtTurn(highestIndex).getUsername() << endl;

    return highestIndex;
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