#ifndef GAME_HPP
#define GAME_HPP


using namespace std;

class Game {
    protected:
        int round;
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
        virtual void start();

        /**
         * @brief winning condition : one of the players has 2^32>= points
         * 
         * @return true 
         * @return false 
         */
        virtual bool isWinning()=0;

        /**
         * @brief is round over
         * 
         */
        virtual bool isRoundOver()=0;
        // saat semua player telah mendapat giliran

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

        /**
         * @brief menjalankan game 1 ronde
         * 
         */
        virtual void startRound()=0;

};
#endif