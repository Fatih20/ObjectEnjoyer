#ifndef _PLAYER_CANGKUL_HPP_
#define _PLAYER_CANGKUL_HPP_

#include "../Player/Player.hpp"
#include "../DeckPlayer/DeckPlayer.hpp"
#include "../ColorCard/ColorCard.hpp"

class PlayerCangkul : public Player<ColorCard> {
    private:
        static int num_player;

        Deck<ColorCard> playableDeck;
        //for some reason DeckPlayer wont work here

    public:
        PlayerCangkul();

        PlayerCangkul(int gameID);

        void updatePlayableDeck();

        void updatePlayableDeck(Color color);

        void resetPlayableDeck();

        ColorCard ejectPlayableDeck(int index);

        int getNumberOfPlayableCard();

        void printPlayableCard();

        bool isWinner();

        ColorCard playCard(int index);
};

#endif