#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Deck/Deck.hpp"
#include "../ColorCard/ColorCard.hpp"
#include <vector>
using namespace std;

typedef enum{
            HIGH_CARD,
            PAIR,
            TWO_PAIRS,
            THREE_OF_A_KIND,
            STRAIGHT,
            FLUSH,
            FULL_HOUSE,
            FOUR_OF_A_KIND,
            STRAIGHT_FLUSH,
} CombinationType;

class Combination{
    private:
        CombinationType combinationType;
        vector <ColorCard> allCards;
        vector <ColorCard> playerCards;
        vector <ColorCard> usedCards;
        ColorCard highestCard;
        ColorCard highestPlayerCard;
    public:
        Combination(vector<ColorCard> player, vector<ColorCard> table);

        void calculate(vector<ColorCard> player, vector<ColorCard> table);

        void isStraightFlush();

        void isFourOfAKind();

        void isFullHouse();

        void isFlush();

        void isStraight();

        void isThreeOfAKind();

        void isTwoPair();

        void isOnePair();

        bool inPlayer(vector<ColorCard> cards);

        ColorCard getHighestPlayerCard(vector<ColorCard> cards);

        void print();

        bool operator<(Combination& other);

        bool operator>(Combination& other);

        bool operator==(Combination& other);

        vector<ColorCard> getUsedCards();
};

#endif