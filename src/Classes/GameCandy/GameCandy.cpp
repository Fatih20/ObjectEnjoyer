#include "GameCandy.hpp"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> commandOption{"next", "double", "half", "gamestat", "help", "mycard", "combination",
                             "re-roll", "quadruple", "quarter",
                             "reverse", "swap", "switch", "abilityless"};

GameCandy::GameCandy()
{
    splashScreen();

    // Initialize deck color and deck ability
    newDeck();

    // Initialize empty table cards
    DeckGame<ColorCard> tableCard;
    this->tableCard = tableCard;

    // Initialize players
    PlayerInGameCandy pIGC(this->deckGame, 7);
    this->players = pIGC;
    round = 1;
    giftPoint = 64;
}

void GameCandy::start()
{
    string cmd;
    while (!isWinning())
    {
        round = 1;
        while (round != 7)
        {
            cout << "\033[1m\033[32m"
                 << "\nRound " << round << " begin \n\n"
                 << "\033[0m";
            roundAction();
            while (!isRoundOver())
            {
                cout << "\033[1m\033[37m"
                     << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn"
                     << "\033[0m" << endl;
                cmd = inputCommand();
                while (!playerAction(cmd))
                {
                    cout << "\033[1m\033[37m"
                         << "\nPlayer " << players.getPlayerWithTurn().getUsername() << " turn"
                         << "\033[0m" << endl;
                    cmd = inputCommand();
                }
                players.nextTurn();
                cout << endl
                 << "\033[1m\033[35m"
                 << "-------------------------------------------------------"
                 << "\033[0m" << endl;
            }

            nextRound();
            players.resetRound();
        }
        endOfGame();
        if (!isWinning())
        {
            cout << "\033[1m\033[32m"
                 << "\nNew game starting..\n\n"
                 << "\033[0m";
            newDeck();
            players.redrawAll(this->deckGame);
            players.drawAbilityCardAll(this->deckAbility);
            giftPoint = 64;
        }
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

void GameCandy::endOfGame()
{
    cout << endl
         << "Round 6 Finished." << endl;
    pair<PlayerCandy, Combination> winner = players.rewardHighestCombination(giftPoint, tableCard);
    cout << "This round winner is "
         << "\033[1m\033[37m" << winner.first.getUsername() << "\033[0m" << endl
         << endl;
    printTableCard();
    cout << "\033[1m\033[37m"
         << "Player Cards: "
         << "\033[0m" << endl;
    winner.first.printCard();
    cout << endl;
    cout << "Combo : ";
    winner.second.print();
    cout << endl
         << "Player "
         << "\033[1m\033[37m" << winner.first.getUsername() << "\033[0m"
         << " mendapatkan "
         << "\033[1m\033[37m" << giftPoint << "\033[0m"
         << " poin!" << endl
         << endl;
    players.showLeaderboard();
    if (isWinning())
    {
        giftPoint = 64;
        cout << endl
             << "Game ended." << endl;
        cout << "Game won by " << players.getWinner() << endl;
        SplashScreen::splashScreenWinning();
    }
    else
    {
        cout << endl
             << "No ones win yet." << endl;
        cout << "Game continued." << endl;
    }
}

bool GameCandy::playerAction(string cmd)
{
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    if (cmd == "next")
    {
        cout << "Turn continued to the next player" << endl;
    }
    else if (cmd == "double")
    {
        changeGiftPoinMessage(cmd, 2);
        doublePoint();
    }
    else if (cmd == "half")
    {
        changeGiftPoinMessage(cmd, 0.5);
        halvesPoint();
    }
    else if (cmd == "gamestat")
    {
        displayGameStat();
    }
    else if (cmd == "mycard")
    {
        cout << endl;
        players.getPlayerWithTurn().printCard();
    }
    else if (cmd == "help")
    {
        displayHelp();
    }
    else if (cmd == "combination")
    {
        displayCombiInfo();
    }
    else
    {
        try
        {
            transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
            players.getPlayerWithTurn().useAbility(cmd, *this);
            transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        }
        catch (AbilityNotOwned e)
        {
            cout << e.getMessage(cmd) << endl;
        }
        catch (AbilityNotAvailable e)
        {
            cout << e.getMessage() << endl;
            return false;
        }
    }

    if (cmd == "gamestat" || cmd == "mycard" || cmd == "help" || cmd == "reverse" || cmd == "combination")
    {
        return false;
    }
    else
    {
        return true;
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
            isCommandValid(cmd);
            isValid = true;
        }
        catch (CommandInvalid e)
        {
            cout << endl
                 << "Command '" << e.getInvalidCommand() << "' is invalid" << endl;
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
    else if (round == 1 && it - commandOption.begin() < 7)
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

void GameCandy::doublePoint()
{
    giftPoint *= 2;
}

void GameCandy::halvesPoint()
{
    giftPoint = giftPoint / 2;
}

void GameCandy::quarterPoint()
{
    changeGiftPoinMessage("quarter", 0.25);
    giftPoint = giftPoint / 4;
}

void GameCandy::quadruplePoint()
{
    changeGiftPoinMessage("quadruple", 4);
    giftPoint = giftPoint * 4;
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
    shared_ptr<Quadruple> quad = make_shared<Quadruple>();
    shared_ptr<Quarter> quarter = make_shared<Quarter>();
    shared_ptr<Reroll> quad1 = make_shared<Reroll>();
    shared_ptr<Reverse> quarter1 = make_shared<Reverse>();
    shared_ptr<Swap> quad2 = make_shared<Swap>();
    shared_ptr<Switch> quarter2 = make_shared<Switch>();
    shared_ptr<Abilityless> quad3 = make_shared<Abilityless>();

    AbilityCard ac1(quad);
    AbilityCard ac2(quad2);
    AbilityCard ac3(quad3);
    AbilityCard ac4(quarter);
    AbilityCard ac5(quarter1);
    AbilityCard ac6(quarter2);
    AbilityCard ac7(quad1);

    vector<AbilityCard>
        abilityCards{ac1, ac2, ac3, ac4, ac5, ac6, ac7};
    return abilityCards;
}

void GameCandy::newDeck()
{
    cout << "How do you want to generate Deck?\n";
    cout << "1. Random\n";
    cout << "2. From File\n";
    int option = inputOption(2);
    if (option == 1)
    {
        DeckGame<ColorCard> deck(initilizeDeckGame());
        DeckGame<AbilityCard> deckAbility(initializeAbilityDeck());
        this->deckGame = deck;
        this->deckAbility = deckAbility;
        this->deckGame.shuffle();
        this->deckAbility.shuffle();
    }
    else
    {
        string path;
        bool validPath = false;
        while (!validPath)
        {
            cout << "Input File Path: ";
            cin >> path;
            cout << endl;
            try
            {
                FileReader<ColorCard, AbilityCard> f(path);
                f.read();
                this->deckGame = f.getDeckOrder();
                this->deckAbility = f.getAbilityCardOrder();
                validPath = true;
            }
            catch (FileNotFoundExp err)
            {
                cout << err.what();
            }
            catch (FormatExp err)
            {
                cout << err.what();
            }
            catch (NumberExp err)
            {
                cout << err.what();
            }
        }
    }
    DeckGame<ColorCard> tablecard;
    this->tableCard = tablecard;
}

void GameCandy::roundAction()
{
    if (round == 2)
    {
        players.drawAbilityCardAll(this->deckAbility);
        cout << "Ability cards distributed." << endl;
        cout << "From now on, you can use ability card!" << endl
             << endl;
    }
    if (round <= 5)
    {
        deckGame >> tableCard;
    }
    printTableCard();
}

void GameCandy::printTableCard()
{
    cout << "\033[1m\033[37m"
         << "Table Card: "
         << "\033[0m" << endl;
    cout << "|  ";
    vector<ColorCard> tableVec = tableCard.getDeck();
    for (auto i = tableVec.begin(); i != tableVec.end(); ++i)
    {
        cout << *i;
    }
    cout << endl;
}

void GameCandy::nextRound()
{
    round++;
}

void GameCandy::rerollAbility()
{
    players.redrawCardForCurrentPlayer(this->deckGame);
    cout << endl
         << "Former hand card discarded.." << endl;
    cout << "You got \033[1m\033[37m"
         << "2 new cards "
         << "\033[0m"
         << "which are: " << endl;
    players.getPlayerWithTurn().printCard();
}

void GameCandy::abilitylessAbility()
{
    if (players.isAllAbilityDisable())
    {
        cout << endl
             << "Oops, all player has already used their ability." << endl;
        cout << "You got backfired, now you are the one who's abilityless." << endl;
        cout << "This card was useless " << endl;
    }
    else
    {
        cout << endl
             << "Please choose 1 player to turn off ability on: " << endl;
        players.showPlayerExceptCurrent();
        int rawIndex;
        rawIndex = inputOption(6);
        int properIndex = players.correctedIndexCurrent(rawIndex);
        bool disableUseful = players.disablePlayerAbility(properIndex);
        if (disableUseful)
        {
            cout << "Ability card of player "
                 << "\033[1m\033[37m" << players.getNthPlayer(properIndex) << "\033[0m"
                 << " turned off." << endl;
        }
        else
        {
            cout << "Ability card of player "
                 << "\033[1m\033[37m" << players.getNthPlayer(properIndex) << " has already used."
                 << "\033[0m" << endl;
            cout << "This card was useless" << endl;
        }
    }
}

void GameCandy::reverseAbility()
{
    players.reverseTurnInitial();
    cout << players.getPlayerWithTurn().getUsername() << " do "
         << "\033[1m\033[37m"
         << "reverse"
         << "\033[0m" << endl;
    cout << "Turns order for this round : ";
    players.printTurnRemaining();
    cout << "Turns order for next round : ";
    players.printTurnNext();
}

void GameCandy::swapAbility()
{
    vector<int> exceptedIndex{players.getIndexOfCurrentTurn()};
    cout << endl
         << players.getPlayerWithTurn().getUsername() << " do "
         << "\033[1m\033[37m"
         << "swap"
         << "\033[0m" << endl;
    cout << "Please choose player whose card you want to swap: " << endl;
    players.showPlayerExcept(exceptedIndex);
    int rawFirstPlayerIndex = inputOption(6);

    int properFirstIndex = players.correctedIndexCustom(rawFirstPlayerIndex, exceptedIndex);

    exceptedIndex.push_back(properFirstIndex);

    cout << endl
         << "Please choose other player whose card you want to swap: " << endl;
    players.showPlayerExcept(exceptedIndex);
    int rawSecondPlayerIndex = inputOption(5);

    int properSecondIndex = players.correctedIndexCustom(rawSecondPlayerIndex, exceptedIndex);

    bool firstIsLeft;
    bool secondIsLeft;

    cout << endl
         << "Please choose right/left card " << players.getNthPlayer(properFirstIndex) << " :" << endl
         << "1. Right\n2. Left" << endl;
    firstIsLeft = inputOption(2) == 2 ? true : false;
    cout << endl
         << "Please choose right/left card " << players.getNthPlayer(properSecondIndex) << " :" << endl
         << "1. Right\n2. Left" << endl;
    secondIsLeft = inputOption(2) == 2 ? true : false;

    players.swapCardOfPlayer(properFirstIndex, properSecondIndex, firstIsLeft, secondIsLeft);
}

void GameCandy::switchAbility()
{
    cout << endl
         << players.getPlayerWithTurn().getUsername() << " do "
         << "\033[1m\033[37m"
         << "switch"
         << "\033[0m" << endl;
    cout << "Your card:" << endl;
    players.getPlayerWithTurn().printCard();
    cout << endl
         << "Choose other player to switch:" << endl;
    players.showPlayerExceptCurrent();
    int rawIndex = inputOption(6);
    players.swapDeckOfCurrentWith(rawIndex);
    cout << endl
         << "Both of "
         << "\033[1m\033[37m" << players.getPlayerWithTurn().getUsername() << "'s"
         << "\033[0m"
         << " cards has been switched with "
         << "\033[1m\033[37m" << players.getNthPlayer(players.correctedIndexCurrent(rawIndex)).getUsername() << "\033[0m" << endl;
    cout << "Your card now:" << endl;
    players.getPlayerWithTurn().printCard();
}
void GameCandy::changeGiftPoinMessage(string cmd, double multiplier)
{
    cout << endl
         << players.getPlayerWithTurn().getUsername() << " do "
         << "\033[1m\033[37m" << cmd << "\033[0m"
         << "!" << endl;
    if (giftPoint * multiplier < 1)
    {
        cout << "Unfortunately gift point is already 1." << endl;
        cout << "Gift points wasn't changed, turn continued!" << endl
             << endl;
    }
    else
    {
        string status = multiplier < 1 ? "go down" : "go up";
        cout << "Gift points " << status << " fom "
             << "\033[1m\033[37m" << giftPoint << "\033[0m"
             << " to "
             << "\033[1m\033[37m" << giftPoint * multiplier << "\033[0m"
             << "!" << endl;
    }
}

void GameCandy::displayGameStat()
{
    cout << "\n\033[1m\033[37m"
         << "Gift Point: "
         << "\033[1m\033[33m" << this->giftPoint << "\033[0m" << endl;
    cout << "\033[1m\033[37m"
         << "Turns: ";
    players.printTurn();
    cout << endl;
    cout << endl;
    printTableCard();
}

void GameCandy::displayCombiInfo()
{
    cout << "\033[1m\033[35m"
         << "---------------------------------" << endl;
    cout << "       AVAILABLE COMBINATION" << endl;
    cout << "---------------------------------"
         << "\033[0m" << endl;
    cout << "* 13 > 12 > ... > 1 *" << endl
         << "* Red > Yellow > Blue > Green *" << endl;
    cout << "Combination below written in low priority to high priority order." << endl;
    cout << "- HIGH CARD: Higest value & color card win (compare by value first, then color).\n";
    cout << "- PAIR: A pair of same value card.\n";
    cout << "- TWO PAIR: Two Pair of same value card.\n";
    cout << "- THREE OF A KIND: Triple card of same value.\n";
    cout << "- STRAIGHT: 5 cards of ascending value (highest value win).\n";
    cout << "- FLUSH: 5 cards of same color (highest value win).\n";
    cout << "- FULL HOUSE: 3 same value cards + 2 same value cards (highest value win, 3 cards value checked first).\n";
    cout << "- FOUR OF A KIND: 4 cards of sama value.\n";
    cout << "- STRAIGHT FLUSH: 5 cards of ascending value and same color (highest value win).\n";
}

void GameCandy::displayHelp()
{
    cout << "\033[1m\033[35m"
         << "---------------------------------" << endl;
    cout << "              HELP" << endl;
    cout << "---------------------------------"
         << "\033[0m" << endl;
    cout << "\033[1m\033[37m"
         << "Command: "
         << "\033[0m" << endl;
    cout << "- \"GAMESTAT\": Check game status(turns, current gift points, table card).\n";
    cout << "- \"MYCARD\": Check your hand cards and ability card.\n";
    cout << "- \"COMBINATION\": Check available combination (to plan your move!).\n";
    cout << "- \"NEXT\": Do nothing this round. Turn will be handed over to the next player.\n";
    cout << "- \"REROLL\": Discard your hand cards then takes two new cards from main deck. Only available when you have REROLL Ability Card.\n";
    cout << "- \"DOUBLE\": Double gift points.\n";
    cout << "- \"QUADRUPLE\": Multiple gift points 4 times.\n";
    cout << "- \"HALF\": Divide gift points by the factor of 2.\n";
    cout << "- \"QUARTER\": Divide gift points by the factor of 4.\n";
    cout << "- \"REVERSE\": Reverse player turns, players who have already taken action on that turn will be skipped.\n    Only available when you have REROLL Ability Card. You have one more command available after this command.\n";
    cout << "- \"SWAPCARD\": Swap one other player's hand cards with one other. Choose 2 players, then swap each one of their hand cards.\n    Only available when you have SWAPCARD Ability Card.\n";
    cout << "- \"SWITCH\": Switch your hand cards with other player's hand card. Only available when you have SWITCH Ability Card.\n";
    cout << "- \"ABILITYLESS\": BLock other player's Abilty. If all player has already used their ability, this command will be useless.\n    Only available when you have ABILITYLESS Ability Card.\n";
    cout << "* Commands are case insensitive.\n";
}
