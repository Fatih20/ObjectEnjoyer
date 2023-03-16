#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "../GameException/GameException.hpp"
#include "../FileReader/FileReader.hpp"
#include "../FileReaderException/FileReaderException.hpp"
using namespace std;

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
         * @brief return true if there is a winner
         * 
         * @return true 
         * @return false 
         */
        virtual bool isWinning()=0;

        /**
         * @brief akhir dari maks ronde (belum tentu mendapat pemenang)
         * 
         */
        virtual void endOfGame()=0;

        /**
         * @brief input valid command
         * 
         * @return string 
         */
        virtual string inputCommand()=0;

        /**
         * @brief return true if user command is valid
         * 
         * @return string 
         */
        virtual string isCommandValid(string)=0;

        /**
         * @brief display splash screen
         * 
         */
        virtual void splashScreen();

        /**
         * @brief input valid option with range
         * 
         * @return int 
         */
        int inputOption(int);

        /**
         * @brief true if option valid
         * 
         * @return true 
         * @return false 
         */
        bool isOptionValid(int,int);
};

#endif