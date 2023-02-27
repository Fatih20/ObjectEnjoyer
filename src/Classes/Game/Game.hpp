#ifndef GAME_HPP
#define GAME_HPP

using namespace std;

class Game {
    protected:
        Player* players;        //pemain
        int round;              //ronde permainan
        int giftPoin;           //poin hadiah tiap ronde
        DeckCard mainDeck;      //deck utama
        Player currentTurn;     //pemain giliran saat ini
        int playerTurn[7];      //urutan giliran pemain saat ini
    public:
        /*default cctor*/
        Game();
        // round 1, giftPoint 64, currentTurn p1, playerTurn (p1,p2,p3,p4,p5,p6,p7)

        /*dtor*/
        ~Game();

        /*cctor*/
        Game(const Game&);

        /* Mengembalikan player ke-i*/
        Player getPlayer(int i);

        /* start game */
        void start();
        /* set nickname player
         * loop untill winning condition
         *      if (ronde = 1) : set DeckCard
         *      loop player turn & !winning condition */

        /* winning condition, poin salah satu player >= 2^32*/
        void isWinning();

        /* mengubah nickname semua player sesuai input */
        void setPlayers();

        /* inisiasi mainDeck dan membagikan kartu pemain pada awal ronde (user-input/file based)*/
        void setDeckCard();

        /* mengubah menjadi x kali semula, giftPoin tidak boleh <1*/
        void multiplyGiftPoin();

        /* pembagian kartu ability pada ronde kedua */
        void giveAbilityCard();

        /* memberi giftPoin kepada player pemenang 6 ronde */
        void endOfRound6();

        /* mekanisme giliran pemain, currentPlayer akan input command dan command akan dijalankan */
        void playerTurn();
        
        // blm selesai

};

#endif
