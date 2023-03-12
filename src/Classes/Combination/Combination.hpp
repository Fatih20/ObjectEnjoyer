#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Deck/Deck.hpp"
#include "../ColorCard/ColorCard.hpp"
#include <vector>
using namespace std;

class Combination{
    private:
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
        int score;
        CombinationType combinationType;
        vector <ColorCard> allCards;
        vector <ColorCard> playerCards;
        vector <ColorCard> usedCards;
    public:
        Combination(vector<ColorCard> player, vector<ColorCard> table);

        // void calculate(vector<ColorCard> player, vector<ColorCard> table);

        // bool isStraightFlush(vector<ColorCard> player, vector<ColorCard> table);

        // bool isFourOfAKind(vector<ColorCard> player, vector<ColorCard> table);

        // bool isFullHouse(vector<ColorCard> player, vector<ColorCard> table);

        // bool isFlush(vector<ColorCard> player, vector<ColorCard> table);

        // bool isStraight(vector<ColorCard> player, vector<ColorCard> table);

        // bool isThreeOfAKind(vector<ColorCard> player, vector<ColorCard> table);

        bool isTwoPair(vector<ColorCard> player, vector<ColorCard> table);

        bool isOnePair(vector<ColorCard> player, vector<ColorCard> table);

        void getHighestCard(vector<ColorCard> player, vector<ColorCard> table);

        bool inPlayer();

        void print();
};

#endif