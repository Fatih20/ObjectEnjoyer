#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> commandOption{"next", "double", "half",
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
    } else {
    }
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
    else if (round == 1 && it - commandOption.begin() < 3)
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

    cout << "       _..._                                                                                                                     " << endl;
    cout << "    .-'_..._''.                      _______                                                                                     " << endl;
    cout << "  .' .'      '.\\             _..._   \\  ___ `'.                                              __  __   ___         __.....__      " << endl;
    cout << " / .'                      .'     '.  ' |--.\\  \\.-.          .-            .--./)           |  |/  `.'   `.   .-''         '.    " << endl;
    cout << ". '                       .   .-.   . | |    \\  '\\ \\        / /           /.''\\            |   .-.  .-.   ' /     .-''\"'-.  `.  " << endl;
    cout << "| |                 __    |  '   '  | | |     |  '\\ \\      / /           | |  | |      __   |  |  |  |  |  |/     /________\\   \\ " << endl;
    cout << "| |              .:--.'.  |  |   |  | | |     |  | \\ \\    / /             \\`-' /    .:--.'. |  |  |  |  |  ||                  | " << endl;
    cout << ". '             / |   \\ | |  |   |  | | |     ' .'  \\ \\  / /              /(\"'`    / |   \\ ||  |  |  |  |  |\\    .-------------' " << endl;
    cout << " \\ '.          .`\" __ | | |  |   |  | | |___.' /'    \\ `  /               \\ '---.  `\" __ | ||  |  |  |  |  | \\    '-.____...---. " << endl;
    cout << "  '. `._____.-'/ .'.''| | |  |   |  |/_______.'/      \\  /                 /'"
            "'.\\  .'.''| ||__|  |__|  |__|  `.             .'  "
         << endl;
    cout << "    `-.______ / / /   | |_|  |   |  |\\_______|/       / /                 ||     ||/ /   | |_                   `''-...... -'    " << endl;
    cout << "             `  \\ \\._,\\ '/|  |   |  |             |`-' /                  \'. __// \\ \\._,\\ '/                                    " << endl;
    cout << "                 `--'  `\" '--'   '--'              '..'                    `'---'   `--'  `\"                                     " << endl;
    cout << "\nGame starting...\n\n";
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
    // if(option==1){
    DeckGame<ColorCard> deck(initilizeDeckGame());
    // DeckGame<AbilityCard> abilityCard(initilizeAbilityDeck());
    // } else {
    //     // file reader
    // }
    this->deckGame = deck;
}

void GameCandy::roundAction()
{
    if (round <= 5)
    {
        deckGame >> tableCard;
        cout << "Table card round "<< round << endl << tableCard;
    }
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
