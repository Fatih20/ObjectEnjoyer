#ifndef GAMECANDY_HPP
#define GAMECANDY_HPP

#include "../Game/Game.hpp"
#include "../PlayerInGameCandy/PlayerInGameCandy.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "GameCandyException/GameCandyException.hpp"

using namespace std;

template <typename T>
class GameCandy: public Game<T>{
    private:
        // PlayerInGameCandy players;   // pemain
        // DeckGame<T> deck;            // deck game
        // DeckGame<T> tableCard;       // table card
        int round;                   // ronde
        double giftPoint;            // point hadiah tiap akhir game
    public:
        /**
         * @brief Construct a new Game Candy object
         * 
         */
        GameCandy();
        // jumlah player 7, ronde = 1, giftpoin 64

        /**
         * @brief Start game
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
        void playerAction(int);

        /**
         * @brief 
         * 
         */
        string inputCommand();

        /**
         * @brief 
         * 
         */
        bool isCommandValid(string);
};

#endif