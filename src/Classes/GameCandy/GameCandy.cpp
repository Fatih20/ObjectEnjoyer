#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> commandOption{"next", "double", "half","gamestat","help","mycard",
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
                while(cmd == "gamestat" || cmd == "mycard" || cmd == "help" || cmd == "reverse"){
                    cout << "\033[1m\033[37m" << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn" << "\033[0m" << endl;
                    cmd = inputCommand();
                    playerAction(cmd);                    
                }
                players.nextTurn();
            }
            nextRound();
            players.resetRound();
        }
        endOfGame();
        cout << "\033[1m\033[32m" << "\nNew game starting..\n\n" << "\033[0m";
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
    players.rewardHighestCombination(giftPoint,tableCard);
    cout << "\nRonde 6 selesai.\n";
    cout << "Pemenang babak ini adalah \n" << endl;
    cout << "mendapatkan " << giftPoint << " poin!\n";
    players.showLeaderboard();
    if (isWinning()){
        giftPoint = 64;
        cout << "\nPermainan berakhir.\n";
        cout << "Permainan dimenangkan oleh " << endl;
    } else {
        cout << "\nBelum terdapat pemenang permainan.\n";
        cout << "Permainan dilanjutkan.\n";
    }
}



void GameCandy::playerAction(string cmd)
{
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
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
    } else if (cmd == "mycard"){
        players.getPlayerWithTurn().printColorCard();
        displayPlayerCard();
    } else if (cmd == "help"){
        displayHelp();
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
    else if (round == 1 && it - commandOption.begin() < 6)
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

void GameCandy::displayPlayerCard(){
    players.getPlayerWithTurn().printColorCard();
    // cout  << "\033[1m\033[37m" << "Your Hand Card: " << "\033[0m" << endl;
    // cout << "|  ";
    // vector<ColorCard> handVec = players.getPlayerWithTurn().getHandCards().getDeck();
    // for (auto i = handVec.begin(); i != handVec.end(); ++i){
    //     if((*i).getColor() == GREEN){
    //         cout << "\033[1m\033[32m";
    //     }
    //     else if((*i).getColor() == RED){
    //         cout << "\033[1m\033[31m";
    //     }
    //     else if((*i).getColor() == YELLOW){
    //         cout << "\033[1m\033[33m";
    //     }
    //     else if((*i).getColor() == BLUE){
    //         cout << "\033[1m\033[34m";
    //     }
    //     cout << (*i).getColorAsString() << " " << (*i).getNumber() << "\033[0m" << "  |  ";
    // }
    // cout << endl;
}

void GameCandy::displayHelp(){
    cout << "\033[1m\033[35m" << "---------------------------------" << endl;
    cout << "           HELP" << endl;
    cout << "---------------------------------" << "\033[0m" << endl;
    cout << "\033[1m\033[37m" << "Command: " << "\033[1m\033[33m" << endl;
    cout << "- \"NEXT\":  Do nothing this round. Turn will be handed over to the next player.\n";
    cout << "- \"REROLL\":  Discard your hand cards then takes two new cards from main deck. Only available when you have REROLL Ability Card.\n";
    cout << "- \"DOUBLE\":  Double gift points.\n";
    cout << "- \"QUADRUPLE\":  Multiple gift points 4 times.\n";
    cout << "- \"HALF\":  Divide gift points by the factor of 2.\n";
    cout << "- \"QUARTER\":  Divide gift points by the factor of 4.\n";
    cout << "- \"REVERSE\":  Reverse player turns, players who have already taken action on that turn will be skipped.\n    Only available when you have REROLL Ability Card. You have one more command available after this command.\n";
    cout << "- \"SWAPCARD\":  Swap one other player's hand cards with one other. Choose 2 players, then swap each one of their hand cards.\n    Only available when you have SWAPCARD Ability Card.\n";
    cout << "- \"SWITCH\":  Switch your hand cards with other player's hand card. Only available when you have SWITCH Ability Card.\n";
    cout << "- \"ABILITYLESS\":  BLock other player's Abilty. If all player has already used their ability, this command will be useless.\n    Only available when you have ABILITYLESS Ability Card.\n";
    cout << "* Commands are case insensitive.\n";
}
