#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include "Classes/Card/Card.hpp"
#include <Map>

typedef enum{
    GREEN,
    BLUE,
    YELLOW,
    RED
} Color;

std::map<std::pair<int, Color>, double> cardWeight; // Akan dipakai untuk menghitung bobot kartu [biar spek map kepake hehe]

class ColorCard: public Card<int> {
    private:
        Color color;
    
    public:
        /**
         * @brief Construct a new Color Card object with given value and color
         * 
         * @param value The face value of the card
         * @param color The color of the card (GREEN, BLUE, YELLOW, RED)
         */
        ColorCard(int value, Color color);
        // CCtor dan assignment operator tidak perlu karena tidak ada pointer
        // Dtor tidak perlu karena hanya menyimpan data sederhana

        /**
         * @brief Get the color of the card
         * 
         */
        Color getColor();

        /**
         * @brief Get the card weight based on the value and color relative to other color cards
         * 
         */
        int getValue();
};

typedef enum{
    HIGH,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
} Combination;

std::map<Combination, double> combinationWeight; // Akan dipakai untuk menghitung bobot kombinasi kartu [biar spek map kepake hehe]

/**
 * @brief Get the Combination Weight of the given combination of cards
 * 
 */
double getCombinationWeight(Card<int> cards[]);

#endif 