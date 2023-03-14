#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> commandOption{"gamestat", "next", "double", "half",
                             "re-roll", "quadruple", "quarter",
                             "reverse", "swap", "switch", "abilityless"};

GameCandy::GameCandy()
{
    splashScreen();

    newDeck1();

    PlayerInGameCandy players(deckGame, 7);
    this->players = players;

    DeckGame<ColorCard> tableCard;
    this->tableCard = tableCard;
    // table card empty

    round = 1;
    giftPoint = 64;
}

void GameCandy::start()
{
    cout << "\nNew game start\n";
    string cmd;
    while (!isWinning())
    {
        // inisialisasi game baru -> player sama, deckCard baru
        newDeck1();
        while (round != 6){
            cout << "\nRound " << round << " begin\n\n";
            roundAction();
            while (!isRoundOver())
            {
                cout << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn\n";
                cmd = inputCommand();
                playerAction(cmd);
                while(cmd == "gamestat"){
                    cout << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn\n";
                    cmd = inputCommand();
                    playerAction(cmd);                    
                }
                players.nextTurn();
            }
            nextRound();
            players.resetRound();
        }

    }

    
}

bool GameCandy::isWinning()
{
    return players.winnerExist();
}

bool GameCandy::isRoundOver()
{
    // true jika semua player telah mendapat giliran
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

void GameCandy::startRound()
{
    //     switch (round)
    //     {
    //     case 1:
    //         //bagi color card
    //         break;
    //     case 2:
    //         //bagi ability card
    //     }

    for (int i = 0; i < 7; i++)
    {
        string cmd = inputCommand();
        playerAction(cmd);
        // nextTurn();
    }
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
        cout << endl << "\033[1m\033[37m" << "Table Card: " << "\033[0m" << endl;
        printTableCard();
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
            // cout << isCommandValid(cmd) << endl;
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
    cout << "\033[1m\033[35m";
    cout << "       _..._                                                       " << endl;
    cout << "    .-'_..._''.                      _______                       " << endl;
    cout << "  .' .'      '.\\             _..._   \\  ___ `'.                  " << endl;
    cout << " / .'                      .'     '.  ' |--.\\  \\.-.          .-  " << endl;
    cout << ". '                       .   .-.   . | |    \\  '\\ \\        / / " << endl;
    cout << "| |                 __    |  '   '  | | |     |  '\\ \\      / /   " << endl;
    cout << "| |              .:--.'.  |  |   |  | | |     |  | \\ \\    / /    " << endl;
    cout << ". '             / |   \\ | |  |   |  | | |     ' .'  \\ \\  / /    " << endl;
    cout << " \\ '.          .`\" __ | | |  |   |  | | |___.' /'    \\ `  /     " << endl;
    cout << "  '. `._____.-'/ .'.''| | |  |   |  |/_______.'/      \\  /        "<< endl;
    cout << "    `-.______ / / /   | |_|  |   |  |\\_______|/       / /         " << endl;
    cout << "             `  \\ \\._,\\ '/|  |   |  |             |`-' /        " << endl;
    cout << "                 `--'  `\" '--'   '--'              '..'           " << endl;                                                 
    cout << "                    __  __   ___         __.....__               " << endl;                
    cout << "  .--./)           |  |/  `.'   `.   .-\'\'         '.             " << endl;     
    cout << " /.\'\'\\\\            |   .-.  .-.   \' /     .-''\"'-.  `.           " << endl;       
    cout << "| |  | |      __   |  |  |  |  |  |/     /________\\   \\          " << endl;
    cout << " \\`-\' /    .:--.\'. |  |  |  |  |  ||                  |          " << endl;
    cout << " /(\"\'`    / |   \\ ||  |  |  |  |  |\\    .-------------\'          " << endl;
    cout << " \\ \'---.  `\" __ | ||  |  |  |  |  | \\    \'-.____...---.          " << endl;
    cout << "  /\'\"\"\'.\\  .\'.\'\'| ||__|  |__|  |__|  `.             .\'           " << endl;
    cout << " ||     ||/ /   | |_                   `\'\'-...... -\'             " << endl;
    cout << " \'.  __// \\ \\._,\\ \'/                                             " << endl;
    cout << "  `'---'   `--' `\"                                              " << endl;
    cout << "\033[0m";
    cout << "\033[1m\033[32m" << "\nGame starting...\n\n" << "\033[0m";
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
    
}

void GameCandy::roundAction()
{
    if (round <= 5)
    {
        deckGame >> tableCard;
        printTableCard();
    }
}

void GameCandy::printTableCard(){
    cout << "Table card round "<< round << endl << "|  ";
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
    round = (round + 1) % 6;
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