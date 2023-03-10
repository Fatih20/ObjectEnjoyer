#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Deck/Deck.hpp"

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
    public:
        /**
         * @brief Calculate the score of the player's hand
         * 
         * @param player The player's hand
         * @param table The table's cards
         * @return int The score of the player's hand
         */
        static int calculate(Deck<int> player, Deck<int> table);

        bool isStraightFlush(Deck<int> player, Deck<int> table);

        bool isFourOfAKind(Deck<int> player, Deck<int> table);

        bool isFullHouse(Deck<int> player, Deck<int> table);

        bool isFlush(Deck<int> player, Deck<int> table);

        bool isStraight(Deck<int> player, Deck<int> table);

        bool isThreeOfAKind(Deck<int> player, Deck<int> table);

        bool isTwoPairs(Deck<int> player, Deck<int> table);

        bool isPair(Deck<int> player, Deck<int> table);

        bool isHighestCombo(Deck<int> table);
};

#endif