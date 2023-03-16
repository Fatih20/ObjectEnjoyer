#ifndef GAMECANDY_HPP
#define GAMECANDY_HPP

#include "../Game/Game.hpp"
#include "../PlayerInGameCandy/PlayerInGameCandy.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "../GameCandyException/GameCandyException.hpp"
#include "../Abilities/Abilities.hpp"
#include "../SplashScreen/SplashScreen.hpp"
#include "../PlayerException/PlayerException.hpp"
#include "../Combination/Combination.hpp"
#include <vector>
using namespace std;

class GameCandy : public Game
{

private:
    PlayerInGameCandy players;     // pemain
    DeckGame<ColorCard> deckGame;  // deck game
    DeckGame<ColorCard> tableCard; // table card
    DeckGame<AbilityCard> deckAbility;
    int round;        // ronde
    long long giftPoint; // point hadiah tiap akhir game
    void multiplyGiftPoint(double multiplier);
    void operator*=(double multiplier);
    /**
     * @brief private method to firmat print tabke card
     *
     */
    void printTableCard();

public:
    /**
     * @brief Construct a new Game Candy object
     *
     */
    GameCandy();
    // jumlah player 7, ronde = 1, giftpoin 64

    /**
     * @brief start game candy
     *
     */
    void start();

    /**
     * @brief Splash Screen
     *
     */
    void splashScreen();

    /**
     * @brief winning condition : one of the players has 2^32>= points
     *
     * @return true
     * @return false
     */
    bool isWinning();

    /**
     * @brief is round over
     *
     */
    bool isRoundOver();

    /**
     * @brief begin new game with same players, different deck card
     *
     */
    void newGame();
    // new deck card

    /**
     * @brief akhir dari maks ronde (belum tentu mendapat pemenang)
     *
     */
    void endOfGame();

    /**
     * @brief mekanisme giliran pemain, currentPlayer akan input command dan command akan dijalankan
     *
     */
    bool playerAction(string action);

    /**
     * @brief
     *
     */
    string inputCommand();

    /**
     * @brief if command valid return command
     *
     * @param command
     * @return int
     */
    string isCommandValid(string command);

    /**
     * @brief create deck game of game candy
     *
     */
    vector<ColorCard> initilizeDeckGame();

    /**
     * @brief initiate deckgame, deckplayer, and playerability
     * 
     */
    void newDeck1();

    /**
     * @brief perform actions in specific round
     * 
     */
    void roundAction();

    /**
     * @brief increment round by 1
     * 
     */
    void nextRound();

    /**
     * @brief Double the gift point
     *
     */
    void doublePoint();

    /**
     * @brief Quadruple the gift point
     *
     */
    void quadruplePoint();

    /**
     * @brief Halves the gift point
     *
     */
    void halvesPoint();

    /**
     * @brief Quarter the gift point
     *
     */
    void quarterPoint();

    /**
     * @brief create ability deck of game candy
     *
     */
    vector<AbilityCard> initializeAbilityDeck();

    /**
     * @brief performs reroll ability
     * 
     */
    void rerollAbility();

    /**
     * @brief performs abilityless ability
     * 
     */
    void abilitylessAbility();

    /**
     * @brief performs reverse ability
     * 
     */
    void reverseAbility();

    /**
     * @brief performs switch ability
     * 
     */
    void switchAbility();

    /**
     * @brief performs swap ability
     * 
     */
    void swapAbility();

    /**
     * @brief display a message if there is a change in gift points.
     * 
     */
    void changeGiftPoinMessage(string, double);

    /**
     * @brief display game status
     * 
     */
    void displayGameStat();

    /**
     * @brief display help
     * 
     */
    void displayHelp();

    /**
     * @brief display combination info
     * 
     */
    void displayCombiInfo();

};

#endif