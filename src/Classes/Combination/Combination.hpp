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
                CombinationType type; // type of the combination

                /**
                 * @brief Convert the combination type to a string
                 * 
                 */
                std::string getTypeString();

                /**
                 * @brief Remove the cards that are not needed to make the combination
                 * 
                 */
                void reduceCards();

                /**
                 * @brief Check if the combination is a pair
                 * 
                 */
                bool isPair();

                /**
                 * @brief Check if the combination is a two pairs
                 * 
                 */
                bool isTwoPairs();

                /**
                 * @brief Check if the combination is a three of a kind
                 * 
                 */
                bool isThreeOfAKind();

                /**
                 * @brief Check if the combination is a straight
                 * 
                 */
                bool isStraight();

                /**
                 * @brief Check if the combination is a flush
                 * 
                 */
                bool isFlush();

                /**
                 * @brief Check if the combination is a full house
                 *  
                 */
                bool isFullHouse();

                /**
                 * @brief Check if the combination is a four of a kind
                 * 
                 */
                bool isFourOfAKind();

                /**
                 * @brief Check if the combination is a straight flush
                 * 
                 */
                bool isStraightFlush();

                /**
                 * @brief set the combo type for efficiency
                 * 
                 */
                CombinationType setComboType();

            public:
                /**
                 * @brief Construct a new Combo object with one dummy card
                 * 
                 */
                Combo();

                /**
                 * @brief Construct a new Combo object with the given cards
                 * 
                 */
                Combo(Deck<ColorCard> cards);

                /**
                 * @brief Get the Highest Card Played in the combination
                 * 
                 * @return ColorCard 
                 */
                ColorCard getHighestCard();

                /**
                 * @brief Get all the cards used to make the combination
                 * 
                 */
                Deck<ColorCard> getCards();

                /**
                 * @brief Get the type of the combination
                 * 
                 */
                CombinationType getType();

                /**
                 * @brief Check if the combination uses at least one of the cards from the given deck
                 *  
                 */
                bool useOneOf(Deck<ColorCard> cards);

                /**
                 * @brief Get the Highest Card ni the intersection between the cards used to make the combination and the given cards
                 * 
                 */
                ColorCard getHighestCardIntersection(Deck<ColorCard> cards);

                /**
                 * @brief Print the combination
                 * 
                 */
                void print();

                /**
                 * @brief Overload the < operator to compare two combinations using the rules of poker
                 * 
                 */
                bool operator<(Combo rhs);

                /**
                 * @brief Overload the <= operator to compare two combinations using the rules of poker
                 * 
                 */
                bool operator<=(Combo rhs);

                /**
                 * @brief Overload the > operator to compare two combinations using the rules of poker
                 * 
                 */
                bool operator>(Combo rhs);

                /**
                 * @brief Overload the >= operator to compare two combinations using the rules of poker
                 * 
                 */
                bool operator>=(Combo rhs);

                /**
                 * @brief Overload the == operator to compare two combinations using the rules of poker
                 * 
                 */
                bool operator==(Combo rhs);
        };

        Combo bestCombo; // best combination found
        Deck<ColorCard> allCards; // all cards played for this combination
        Deck<ColorCard> playerCards; // cards played by the player

        /**
         * @brief Get the Best Combo possible from all permutation of the given cards
         * 
         */
        Combo getBestCombo();

        /**
         * @brief Get the Highest Card Played by the player in the combination
         * 
         */
        ColorCard getHighestPlayerCard();
    
    public:
        /**
         * @brief Construct a new Combination object with one deck
         * 
         */
        Combination(Deck<ColorCard> cards);

        /**
         * @brief Construct a new Combination object with two decks
         * 
         * @param player Cards played by the player
         * @param table Cards played on the table
         */
        Combination(Deck<ColorCard> player, Deck<ColorCard> table);

        /**
         * @brief Print the combination details
         * 
         */
        void print();

        /**
         * @brief Overload the < operator to compare two combinations using the rules of poker
         * 
         */
        bool operator<(Combination rhs);

        /**
         * @brief Overload the <= operator to compare two combinations using the rules of poker
         * 
         */
        bool operator<=(Combination rhs);

        /**
         * @brief Overload the > operator to compare two combinations using the rules of poker
         * 
         */
        bool operator>(Combination rhs);

        /**
         * @brief Overload the >= operator to compare two combinations using the rules of poker
         * 
         */
        bool operator>=(Combination rhs);

        /**
         * @brief Overload the == operator to compare two combinations using the rules of poker
         * 
         */
        bool operator==(Combination rhs);
};

#endif