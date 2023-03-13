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
        /**
         * Class to represent a combo in poker
         * WORTH NOTING THAT THE CHECKING IS USING HEURISTICS
         */
        class Combo{
            private:
                Deck<ColorCard> cards; // cards used to make the combination
                ColorCard highestCard; // highest card in the combination

                std::string getTypeString();

                void reduceCards();

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
                Deck<ColorCard> getCards();
                CombinationType getType();

                bool useOneOf(Deck<ColorCard> cards);
                ColorCard getHighestCardIntersection(Deck<ColorCard> cards);

                void print();

                bool operator<(Combo rhs);
                bool operator<=(Combo rhs);
                bool operator>(Combo rhs);
                bool operator>=(Combo rhs);
                bool operator==(Combo rhs);
        };

        Combo bestCombo; // best combination found
        Deck<ColorCard> allCards; // all cards played for this combination
        Deck<ColorCard> playerCards; // cards played by the player

        Combo getBestCombo();

        ColorCard getHighestPlayerCard();
    
    public:
        Combination(Deck<ColorCard> cards);

        Combination(Deck<ColorCard> player, Deck<ColorCard> table);

        void print();

        bool operator<(Combination rhs);

        bool operator<=(Combination rhs);

        bool operator>(Combination rhs);

        bool operator>=(Combination rhs);

        bool operator==(Combination rhs);
};

#endif