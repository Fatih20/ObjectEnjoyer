#ifndef _GAME_CANGKUL_HPP_
#define _GAME_CANGKUL_HPP_

#include <string>
#include "../Game/Game.hpp"
#include "../GameCangkulException/GameCangkulException.hpp"
#include "../PlayerInGameCangkul/PlayerInGameCangkul.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "../ColorCard/ColorCard.hpp"

class GameCangkul : public Game {
private:
     PlayerInGameCangkul players;
     DeckGame<ColorCard> deckGame;
     DeckGame<ColorCard> deckTable;

     vector<string> commandOption;

public:
    /**
         * @brief Construct a new Game object
         *
         */
    GameCangkul();
    // round = 1

    /**
     * @brief start game
     *
     */
    void start();

    /**
     * @brief winning condition : one of the players has 2^32>= points
     *
     * @return true
     * @return false
     */
    bool isWinning();

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

    std::string inputCommand();

    std::string isCommandValid(std::string);

    void splashScreen();

    int inputOption(int);


    // TODO: nantinya akan dibuat method di deckgame
    std::vector<ColorCard> initializeDeckGame();


};

#endif