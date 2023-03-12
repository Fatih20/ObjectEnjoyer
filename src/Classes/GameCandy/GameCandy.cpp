#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

GameCandy::GameCandy()
{
    splashScreen();

    DeckGame<ColorCard> deck;
    // DeckGame<AbilityCard> abilityCard;
    // input randomize/from file

    DeckGame<ColorCard> tableCard;
    // empty

    DeckGame<ColorCard> playerDeck;
    // draw playerDeck from deckGame
    
    PlayerInGameCandy players(playerDeck, 7);
    this->players = players;

    this->deck = deck;
    this->tableCard = tableCard;
    // this->abilityCard = abilityCard;

    round = 1;
    giftPoint = 64;
}

void GameCandy::start()
{
    cout << "New game start\n";
    while (!isWinning())
    {
        // inisialisasi game baru -> player sama, deckCard baru
        cout << "Round " << round << " begin\n";
        newGame();
        while (!isRoundOver())
        {
            
            inputCommand();
        }
    }
}

bool GameCandy::isWinning()
{
    // return (winningPlayer()!=0)
    return false;
}


bool GameCandy::isRoundOver()
{
    // true jika semua player telah mendapat giliran
    return players.getIsRoundComplete();
}


void GameCandy::newGame()
{
    // deck card baru
}

void GameCandy::endOfGame()
{
    // i = winningPlayer();
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
    // switch (cmd)
    // {
    // case 1:
    //     nextCommand();
    //     break;

    // default:
    //     break;
    // }
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
            cout << isCommandValid(cmd) << endl;
            isCommandValid(cmd);
            isValid = true;
        }
        catch (CommandInvalid e)
        {
            cout << "Command '" << e.getInvalidCommand() << "' is invalid\n\n";
        }
    }
    return cmd;
}


string GameCandy::isCommandValid(string userCommand)
{

    string oriCommand = userCommand;
    transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);

    map<string, Command>::iterator it;
    it = cmd.find(userCommand);

    if (it != cmd.end())
    {
        // userCommand valid
        return it->first;
    }
    else
    {
        // userCommand invalid
        throw CommandInvalid(oriCommand);
    }
}

template <typename T>
void GameCandy::splashScreen(){

    cout << "       _..._                                                                                                                     " << endl;
    cout << "    .-'_..._''.                      _______                                                                                     " << endl;
    cout << "  .' .'      '.\\             _..._   \\  ___ `'.                                              __  __   ___         __.....__      " << endl;
    cout << " / .'                      .'     '.  ' |--.\\  \\.-.          .-            .--./)           |  |/  `.'   `.   .-''         '.    " << endl;
    cout << ". '                       .   .-.   . | |    \\  '\\ \\        / /           /.''\\            |   .-.  .-.   ' /     .-''\"'-.  `.  " << endl;
    cout << "| |                 __    |  '   '  | | |     |  '\\ \\      / /           | |  | |      __   |  |  |  |  |  |/     /________\\   \\ " << endl;
    cout << "| |              .:--.'.  |  |   |  | | |     |  | \\ \\    / /             \\`-' /    .:--.'. |  |  |  |  |  ||                  | " << endl;
    cout << ". '             / |   \\ | |  |   |  | | |     ' .'  \\ \\  / /              /(\"'`    / |   \\ ||  |  |  |  |  |\\    .-------------' " << endl;
    cout << " \\ '.          .`\" __ | | |  |   |  | | |___.' /'    \\ `  /               \\ '---.  `\" __ | ||  |  |  |  |  | \\    '-.____...---. " << endl;
    cout << "  '. `._____.-'/ .'.''| | |  |   |  |/_______.'/      \\  /                 /'""'.\\  .'.''| ||__|  |__|  |__|  `.             .'  " << endl;
    cout << "    `-.______ / / /   | |_|  |   |  |\\_______|/       / /                 ||     ||/ /   | |_                   `''-...... -'    " << endl;
    cout << "             `  \\ \\._,\\ '/|  |   |  |             |`-' /                  \'. __// \\ \\._,\\ '/                                    " << endl;
    cout << "                 `--'  `\" '--'   '--'              '..'                    `'---'   `--'  `\"                                     " << endl;
    cout << "/nGame starting..."
}


void GameCandy::multiplyGiftPoint(double multiplier)
{
    giftPoint *= multiplier;
}

void GameCandy::operator*=(double multiplier)
{
    multiplyGiftPoint(multiplier);
}
