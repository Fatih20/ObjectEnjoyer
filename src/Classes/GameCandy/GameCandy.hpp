#ifndef GAMECANDY_HPP
#define GAMECANDY_HPP

#include "../Game/Game.hpp"
#include "../PlayerInGameCandy/PlayerInGameCandy.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "../GameCandyException/GameCandyException.hpp"
#include <vector>
using namespace std;

class GameCandy : public Game
{

private:
    PlayerInGameCandy players;     // pemain
    DeckGame<ColorCard> deckGame;  // deck game
    DeckGame<ColorCard> tableCard; // table card
    DeckGame<AbilityCard> abilityCard;
    int round;        // ronde
    double giftPoint; // point hadiah tiap akhir game
    void multiplyGiftPoint(double multiplier);
    void operator*=(double multiplier);

public:
    /**
     * @brief Construct a new Game Candy object
     *
     */
    GameCandy();
    // jumlah player 7, ronde = 1, giftpoin 64

    /**
     * @brief
     *
     */
    void start();

    /**
     * @brief Spash Screen
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
     * @brief menjalankan game 1 ronde
     *
     */
    void startRound();

    /**
     * @brief mekanisme giliran pemain, currentPlayer akan input command dan command akan dijalankan
     *
     */
    void playerAction(string action);

    /**
     * @brief
     *
     */
    string inputCommand();

    /**
     * @brief if command valid return enum value of the user input command,
     * else throw exception
     *
     * @param command
     * @return int
     */
    string isCommandValid(string command);

    /**
     * @brief
     *
     */
    vector<ColorCard> initilizeDeckGame();

    // vector<AbilityCard> initilizeAbilityDeck();

    // pair<DeckGame<ColorCard>,DeckGame<AbilityCard>> newDeck();

    void newDeck1();

    void roundAction();

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
     * @brief
     *
     */

    // vector<AbilityCard> initilizeAbilityDeck();

    // pair<DeckGame<ColorCard>,DeckGame<AbilityCard>> newDeck();
};

#endif