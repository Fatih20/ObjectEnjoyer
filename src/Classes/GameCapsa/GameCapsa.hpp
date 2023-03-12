#ifndef GAMECAPSA_HPP
#define GAMECAPSA_HPP

#include "../Game/Game.hpp"
#include "../DeckGame/DeckGame.hpp"
#include <map>
using namespace std;

template <typename T>
class GameCapsa: public Game<T>{
    private:
        // PlayerInGameCapsa players;   // pemain
        // DeckGame<T> deck;            // deck game
    public:
        /**
         * @brief Construct a new Game Capsa object
         * 
         */
        GameCapsa();

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
        void playerAction(int action);

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

        void splashScreen();

};

#endif