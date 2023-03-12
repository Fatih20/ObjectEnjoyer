#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

GameCandy::GameCandy()
{
    splashScreen();

    // pair<DeckGame<ColorCard>,DeckGame<AbilityCard>> deck = newDeck();
    DeckGame<ColorCard> deck = newDeck1();
    this->deckGame = deck;
    // this->deckGame = deck.first;
    // this->abilityCard = deck.second;

    DeckGame<ColorCard> tableCard;
    this->tableCard = tableCard;
    // empty

    DeckGame<ColorCard> playerDeck;
    // draw playerDeck from deckGame
    
    PlayerInGameCandy players(playerDeck, 7);
    this->players = players;

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

    vector<string>::iterator it;
    it = find(cmd.begin(),cmd.end(),userCommand);

    if (it != cmd.end())
    {
        // userCommand valid
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

vector<ColorCard> GameCandy::initilizeDeckGame()
{
    vector<ColorCard> vec;
    Color color;
    for(int i=0; i<4; i++){
        for (int j=1; i<=13; j++){
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
            ColorCard colorCard(j,color);
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

DeckGame<ColorCard> GameCandy::newDeck1(){
    cout << "How do you want to generate Deck?\n";
    cout << "1. Random\n";
    cout << "2. From File\n";
    int option = inputOption(2);
    // if(option==1){
        DeckGame<ColorCard> deck(initilizeDeckGame());
        // DeckGame<AbilityCard> abilityCard(initilizeAbilityDeck());
        return deck;
    // } else {
    //     // file reader
    // }
}
