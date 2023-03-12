
#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

GameCandy::GameCandy()
{
    splashScreen();
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
    return false;
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


void GameCandy::splashScreen()
{
    cout << "Game Candy Splash screen\n";
}


void GameCandy::multiplyGiftPoint(double multiplier)
{
    giftPoint *= multiplier;
}

void GameCandy::operator*=(double multiplier)
{
    multiplyGiftPoint(multiplier);
}
