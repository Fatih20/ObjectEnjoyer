#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Deck/Deck.hpp"
#include "../ColorCard/ColorCard.hpp"

typedef enum{
    HIGH_CARD,
    PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
} CombinationType;

class Combination{
    private:
        class Combo{
                private:
                    Deck<ColorCard> cards; // cards used to make the combination
                    ColorCard highestCard; // highest card in the combination

                    bool isPair();
                    bool isTwoPairs();
                    bool isThreeOfAKind();
                    bool isStraight();
                    bool isFlush();
                    bool isFullHouse();
                    bool isFourOfAKind();
                    bool isStraightFlush();

                public:
                    Combo();
                    Combo(Deck<ColorCard> cards);
                    ColorCard getHighestCard();
                    CombinationType getType();
                    Deck<ColorCard> getCards();
                    bool useOneOf(Deck<ColorCard> cards);
                    void print();

                    bool operator<(Combo& rhs);
                    bool operator>(Combo& rhs);
                    bool operator==(Combo& rhs);
            };

        Combo bestCombo; // best combination found
        Deck<ColorCard> allCards; // all cards played for this combination
        Deck<ColorCard> playerCards; // cards played by the player
        ColorCard highestPlayerCard; // highest card played by the player in the combination

        /**
         * @brief Get the Best Combo object from all the possible combinations
         * 
         */
        Combo getBestCombo();

        /**
         * @brief Get the Highest Card Played by the Player in the Combination
         * 
         */
        ColorCard getHighestPlayerCard();

    public:
        /**
         * @brief Construct a new Combination object
         * 
         * @param player The cards played by the player
         * @param table The cards played on the table
         */
        Combination(Deck<ColorCard> player, Deck<ColorCard> table);

        /**
         * @brief Print the combination to the console (DEBUGGING PURPOSE)
         * 
         */
        void print();

        /**
         * @brief Compare two combinations and determine if the first is worse than the second
         * 
         */
        friend bool operator<(Combination& lhs, Combination& rhs);

        /**
         * @brief Compare two combinations and determine if the first is better than the second
         * 
         */
        friend bool operator>(Combination& lhs, Combination& rhs);

        /**
         * @brief Compare two combinations and determine if they are equal
         * 
         */
        friend bool operator==(Combination& lhs, Combination& rhs);
};

#endif