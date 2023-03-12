#ifndef GAME_HPP
#define GAME_HPP

#include <string>
using namespace std;

template <typename T>
class Game {
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game();
        // round = 1

        /**
         * @brief start game
         * 
         */
        virtual void start()=0;

        /**
         * @brief winning condition : one of the players has 2^32>= points
         * 
         * @return true 
         * @return false 
         */
        virtual bool isWinning()=0;

        /**
         * @brief begin new game with same players, different deck card
         * 
         */
        virtual void newGame()=0;
        // new deck card

        /**
         * @brief akhir dari maks ronde (belum tentu mendapat pemenang)
         * 
         */
        virtual void endOfGame()=0;

        virtual string inputCommand()=0;

        virtual string isCommandValid(string)=0;

        virtual void splashScreen();
};

#endif