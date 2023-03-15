#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> commandOption{"next", "double", "half","gamestat",
                             "re-roll", "quadruple", "quarter",
                             "reverse", "swap", "switch", "abilityless",};

GameCandy::GameCandy()
{
    splashScreen();

    newDeck1();

    PlayerInGameCandy players(deckGame, 7);
    this->players = players;

    DeckGame<ColorCard> tableCard;
    this->tableCard = tableCard;

    round = 1;
    giftPoint = 64;
}

void GameCandy::start()
{
    string cmd;
    while (!isWinning())
    {
        round=1;
        while (round != 7){
            cout << "\033[1m\033[32m" << "\nRound " << round << " begin \n\n" << "\033[0m";
            roundAction();
            while (!isRoundOver())
            {
                cout << "\033[1m\033[37m" << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn" << "\033[0m" << endl;
                cmd = inputCommand();
                playerAction(cmd);
                while(cmd == "gamestat"){
                    cout << "\033[1m\033[37m" << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn" << "\033[0m" << endl;
                    cmd = inputCommand();
                    playerAction(cmd);                    
                }
                players.nextTurn();
            }
            nextRound();
            players.resetRound();
        }
        cout << "Permainan berakhir\n";
        players.showLeaderboard();
        cout << "\n";
        
        newDeck1();
    }

    
}

bool GameCandy::isWinning()
{
    return players.winnerExist();
}

bool GameCandy::isRoundOver()
{
    return players.getIsRoundComplete();
}

void GameCandy::newGame()
{
    newDeck1();
    
}

void GameCandy::endOfGame()
{
    vector<string> winner = players.getWinner();
    // players.at(i).addScore(giftPoint);
    giftPoint = 64;
}



void GameCandy::playerAction(string cmd)
{
    if (cmd == "next"){
        cout << "Giliran dilanjut ke pemain selanjutnya\n";
    } else if (cmd == "double"){
        changeGiftPoinMessage(cmd,2);
        doublePoint();
    } else if (cmd == "half"){
        changeGiftPoinMessage(cmd,0.5);
        halvesPoint();
    } else if (cmd == "gamestat"){
        displayGameStat();
    }
    cout << endl << "\033[1m\033[35m" << "---------------------------------" << "\033[0m" << endl;
}

string GameCandy::inputCommand()
{
    string cmd;
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            cout << "> ";
            cin >> cmd;
            isCommandValid(cmd);
            isValid = true;
        }
        catch (CommandInvalid e)
        {
            cout << "\nCommand '" << e.getInvalidCommand() << "' is invalid\n";
        }
    }
    return cmd;
}

string GameCandy::isCommandValid(string userCommand)
{

    string oriCommand = userCommand;
    transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);

    vector<string>::iterator it;
    it = find(commandOption.begin(), commandOption.end(), userCommand);

    if (it != commandOption.end() && round != 1)
    {
        // userCommand valid
        return userCommand;
    }
    else if (round == 1 && it - commandOption.begin() < 4)
    {
        return userCommand;
    }
    else
    {
        // userCommand invalid
        throw CommandInvalid(oriCommand);
    }
}

void GameCandy::splashScreen()
{
    SplashScreen::splashScreenGameCandy();
}

void GameCandy::multiplyGiftPoint(double multiplier)
{
    if (giftPoint>1){
        giftPoint *= multiplier;
    }
}

void GameCandy::operator*=(double multiplier)
{
    multiplyGiftPoint(multiplier);
}

void GameCandy::doublePoint()
{
    multiplyGiftPoint(2);
}

void GameCandy::halvesPoint()
{
    multiplyGiftPoint(0.5);
}

void GameCandy::quarterPoint()
{
    multiplyGiftPoint(0.25);
}

void GameCandy::quadruplePoint()
{
    multiplyGiftPoint(4);
}

vector<ColorCard> GameCandy::initilizeDeckGame()
{
    vector<ColorCard> vec;
    Color color;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            switch (i)
            {
            case 0:
                color = GREEN;
                break;
            case 1:
                color = BLUE;
                break;
            case 2:
                color = YELLOW;
                break;
            case 3:
                color = RED;
                break;
            }
            ColorCard colorCard(j, color);
            vec.push_back(colorCard);
        }
    }
    return vec;
}

// vector<AbilityCard> GameCandy::initilizeAbilityDeck()
// {

// }

// pair<DeckGame<ColorCard>,DeckGame<AbilityCard>> GameCandy::newDeck(){
//     cout << "How do you want to generate Deck?\n";
//     cout << "1. Random\n";
//     cout << "2. From File\n";
//     int option = inputOption(2);
//     if(option==1){
//         DeckGame<ColorCard> deck(initilizeDeckGame());
//         DeckGame<AbilityCard> abilityCard(initilizeAbilityDeck());

//         return make_pair(deck,abilityCard);
//     } else {
//         // file reader
//     }
// }

void GameCandy::newDeck1()
{
    cout << "How do you want to generate Deck?\n";
    cout << "1. Random\n";
    cout << "2. From File\n";
    int option = inputOption(2);
    if(option==1){
        DeckGame<ColorCard> deck(initilizeDeckGame());
        this->deckGame = deck;
        deckGame.shuffle();
        // newDeck1();
    // DeckGame<AbilityCard> abilityCard(initilizeAbilityDeck());
    } else {
        string path;
        bool validPath = false;
        while(!validPath){
            cout << "Input File Path: ";
            cin >> path;
            try{
                FileReader<ColorCard> f(path);
                f.read();
                this->deckGame = f.getDeckOrder();
                validPath = true;
            } catch(FileNotFoundExp err){
                cout << err.what();
            } catch(FormatExp err){
                cout << err.what();
            } catch(NumberExp err){
                cout << err.what();
            }
        }
    }
    DeckGame<ColorCard> tablecard;
    this->tableCard = tablecard;
    
}

void GameCandy::roundAction()
{
    if (round <= 5)
    {
        deckGame >> tableCard;
    }
    printTableCard();
}

void GameCandy::printTableCard(){
    cout  << "\033[1m\033[37m" << "Table Card: " << "\033[0m" << endl;
    cout << "|  ";
    vector<ColorCard> tableVec = tableCard.getDeck();
    for (auto i = tableVec.begin(); i != tableVec.end(); ++i){
        if((*i).getColor() == GREEN){
            cout << "\033[1m\033[32m";
        }
        else if((*i).getColor() == RED){
            cout << "\033[1m\033[31m";
        }
        else if((*i).getColor() == YELLOW){
            cout << "\033[1m\033[33m";
        }
        else if((*i).getColor() == BLUE){
            cout << "\033[1m\033[34m";
        }
        cout << (*i).getColorAsString() << " " << (*i).getNumber() << "\033[0m" << "  |  ";
    }
    cout << endl;
}

void GameCandy::nextRound()
{
    round++;
}

void GameCandy::changeGiftPoinMessage(string cmd,double multiplier){
    cout << endl << players.getPlayerWithTurn().getUsername() << " melakukan " << cmd << "!\n";
    if (giftPoint*multiplier < 1){
        cout << "Sayangnya poin hadiah sudah bernilai 1.\n";
        cout << "Poin hadiah tidak berubah.. Giliran dilanjut!\n\n";
    } else {
        string status = multiplier<1? "turun":"naik";
        cout << "Poin hadiah " << status << " dari " << giftPoint << " menjadi " << giftPoint*multiplier << "!\n";
    }
}

void GameCandy::displayGameStat(){
    cout << "\033[1m\033[35m" << "---------------------------------" << endl;
    cout << "           GAME STATUS" << endl;
    cout << "---------------------------------" << "\033[0m" << endl;
    cout << "\033[1m\033[37m" << "Gift Point: " << "\033[1m\033[33m" << this->giftPoint << "\033[0m" << endl;
    cout << "\033[1m\033[37m" << "Turns: " << endl;
    vector<int> turnsVec = players.getTurns();
    for (auto i = turnsVec.begin(); i != turnsVec.end(); ++i){
        if(*i == players.getIndexOfCurrentTurn()) cout << "\033[1m\033[32m" << "p" << (*i) + 1 << " " << "\033[0m";
        else cout << "p" << (*i) + 1<< " ";
    }
    cout << endl;
    for (auto i = turnsVec.begin(); i != turnsVec.end(); ++i){
        if(*i == players.getIndexOfCurrentTurn()) cout << "\033[1m\033[32m" << "^   " << "\033[0m";
        else cout << "   ";
    }
    cout << endl;
    printTableCard();
}