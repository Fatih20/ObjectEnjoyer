#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "../Player/Player.hpp"

class PlayerCangkul : public Player<ColorCard> {
    private:
        static int num_player;

//        DeckPlayer<ColorCard> playableDeck;

    public:
        PlayerCangkul();

        PlayerCangkul(int gameID);

        void updatePlayableDeck(Color color);

        void resetPlayableDeck();

        int getNumberOfPlayableCard();

        bool isWinner();

        void playCard(int index);


};

#endif