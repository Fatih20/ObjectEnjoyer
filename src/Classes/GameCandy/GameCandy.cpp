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

    // pair<DeckGame<ColorCard>, DeckGame<AbilityCard>> deck = newDeck();
    // this->deckGame = deck.first;
    // this->deckAbility = deck.second;

    newDeck1();

    DeckGame<ColorCard> tableCard;
    this->tableCard = tableCard;
    // table card empty

    // PlayerCandy p(1, deckAbility);
    cout << deckAbility.getNumberOfCards() << endl;

    cout << "Entered initializing pigc" << endl;
    PlayerInGameCandy pIGC(this->deckGame, this->deckAbility, 7);
    this->players = pIGC;
    cout << deckGame;
    round = 1;
    giftPoint = 64;
}

void GameCandy::start()
{
    cout << "\nNew game start\n";
    while (!isWinning())
    {
        // inisialisasi game baru -> player sama, deckCard baru
        newGame();
        cout << "\nRound " << round << " begin\n\n";
        while (!isRoundOver())
        {
            roundAction();
            inputCommand();
            players.nextTurn();
        }
        nextRound();
        players.resetRound();
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
    giftPoint *= multiplier;
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

vector<AbilityCard> GameCandy::initializeAbilityDeck()
{
    cout << "Entered initialize ability deck" << endl;

    Quadruple quad;
    Quarter quarter;
    Quadruple quad1;
    Quarter quarter1;
    Quadruple quad2;
    Quarter quarter2;
    Quadruple quad3;

    AbilityCard ac1(quad);
    AbilityCard ac2(quad2);
    AbilityCard ac3(quad3);
    AbilityCard ac4(quarter);
    AbilityCard ac5(quarter1);
    AbilityCard ac6(quarter2);
    AbilityCard ac7(quad1);

    cout << ac1.value().getName() << endl;

    cout << "Finished ability card initialization" << endl;
    vector<AbilityCard>
        abilityCards{ac1, ac2, ac3, ac4, ac5, ac6, ac7};

    vector<AbilityCard> vec;
    vec.push_back(ac1);
    vec.push_back(ac2);
    vec.push_back(ac3);
    vec.push_back(ac4);
    vec.push_back(ac5);
    vec.push_back(ac6);
    vec.push_back(ac7);

    cout << abilityCards.at(0).value().getName() << endl;
    cout << "Size of ability cards " << abilityCards.size() << endl;
    cout << "Exited initialize ability deck" << endl;

    return vec;
}

pair<DeckGame<ColorCard>, DeckGame<AbilityCard>> GameCandy::newDeck()
{
    cout << "How do you want to generate Deck?\n";
    cout << "1. Random\n";
    cout << "2. From File\n";
    int option = inputOption(2);
    if (option == 1)
    {
        DeckGame<ColorCard> deck(initilizeDeckGame());
        DeckGame<AbilityCard> abilityCard(initializeAbilityDeck());

        return make_pair(deck, abilityCard);
    }
    else
    {
        // file reader
    }
}

void GameCandy::newDeck1()
{
    cout << "How do you want to generate Deck?\n";
    cout << "1. Random\n";
    cout << "2. From File\n";
    int option = inputOption(2);
    // if(option==1){
    DeckGame<ColorCard> deck(initilizeDeckGame());
    DeckGame<AbilityCard> deckAbility(initializeAbilityDeck());

    // DeckGame<AbilityCard> abilityCard(initilizeAbilityDeck());
    // } else {
    //     // file reader
    // }
    this->deckGame = deck;
    this->deckAbility = deckAbility;
}

void GameCandy::roundAction()
{
    cout << "Player " << players.getPlayerWithTurn().getUsername() << " with ability " << players.getPlayerWithTurn().getAbilityName() << " turn\n";
    if (round == 1)
    {
    }
}

void GameCandy::nextRound()
{
    round = (round + 1) % 6;
}
