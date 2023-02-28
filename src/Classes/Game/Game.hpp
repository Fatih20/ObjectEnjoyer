#ifndef GAME_HPP
#define GAME_HPP

#include "../PlayerCollection/PlayerCollection.hpp"
#include "../DeckGame/DeckGame.hpp"

#include <vector>
using namespace std;

class Game {
    protected:
        PlayerCollection players;   //pemain
        int round;                  //ronde permainan
        int giftPoint;              //poin hadiah tiap ronde
        DeckGame mainDeck;          //deck utama
        Player currentTurn;         //pemain giliran saat ini
        vector<int> playerTurn;        //urutan giliran pemain saat ini
    public:
        /**
        * @brief Construct a new Game object.
        * round 1, giftPoint 64, currentTurn p1, playerTurn [1,2,3,4,5,6,7]
        */
        Game();

        /**
         * @brief Destroy the Game object
         * 
         */
        ~Game();

        /**
         * @brief Construct a copy of Game object
         * 
         */
        Game(const Game&);

        /**
         * @brief Get the Player object
         * 
         * @param playerId
         * @return Player 
         */
        Player getPlayer(int playerId);

        /**
         * @brief start game
         * 
         */
        void start();
        /* set nickname player
         * loop untill winning condition
         *      if (ronde = 1) : set DeckCard
         *      loop player turn & !winning condition */

        /**
         * @brief winning condition : one of the players has 2^32>= points
         * 
         * @return true 
         * @return false 
         */
        bool isWinning();

        /**
         * @brief Set the Deck Card object,
         * inisiasi mainDeck dan membagikan kartu pemain pada awal ronde (user-input/file based)
         */
        void setDeckCard();


        /**
         * @brief give gift point to the player with the highest point 
         * 
         */
        void endOfRound6();

        /**
         * @brief mekanisme giliran pemain, currentPlayer akan input command dan command akan dijalankan
         * 
         */
        void playerTurn();

        /**
         * @brief change currentPlayer to the next player in playerTurn
         * 
         */
        void nextTurn();

        /**
         * @brief change playerTurn at the end of the round
         * 
         */
        void nextRoundPlayerTurn();

        ////not for chapsa////
        /**
         * @brief multiply gift point by x
         * 
         * @param x gift point multiplier
         */
        void multiplyGiftPoin(int x);

        /**
         * @brief give players ability card in round 2
         * 
         */
        void giveAbilityCard();

        /**
         * @brief activate ability card that the current player has
         * 
         */
        void activateAbility();

        /**
         * @brief reverse the rest of playerTurn
         * 
         */
        void reverseTurn();

        void commandDOUBLE();
        void commandNEXT();
        void commandHALF();

        void commandREROLL();
        void commandQUADRUPLE();
        void commandHALF();
        void commandQUARTER();
        void commandREVERSE();
        void commandSWAPCARD();
        void commandSWITCH();
        void commandABILITYLESS();

        // blm selesai
};

#endif
