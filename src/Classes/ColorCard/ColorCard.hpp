#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include "Classes/Card/Card.hpp"
#include <Map>
#include <utility>

typedef enum{
    GREEN,
    BLUE,
    YELLOW,
    RED
} Color;

// nanti pindahkan ke cpp
extern const std::map<std::pair<int, Color>, int> cardWeight = {
    {{1, GREEN}, 1}, {{1, BLUE}, 2}, {{1, YELLOW}, 3}, {{1, RED}, 4},
    {{2, GREEN}, 5}, {{2, BLUE}, 6}, {{2, YELLOW}, 7}, {{2, RED}, 8},
    {{3, GREEN}, 9}, {{3, BLUE}, 10}, {{3, YELLOW}, 11}, {{3, RED}, 12},
    {{4, GREEN}, 13}, {{4, BLUE}, 14}, {{4, YELLOW}, 15}, {{4, RED}, 16},
    {{5, GREEN}, 17}, {{5, BLUE}, 18}, {{5, YELLOW}, 19}, {{5, RED}, 20},
    {{6, GREEN}, 21}, {{6, BLUE}, 22}, {{6, YELLOW}, 23}, {{6, RED}, 24},
    {{7, GREEN}, 25}, {{7, BLUE}, 26}, {{7, YELLOW}, 27}, {{7, RED}, 28},
    {{8, GREEN}, 29}, {{8, BLUE}, 30}, {{8, YELLOW}, 31}, {{8, RED}, 32},
    {{9, GREEN}, 33}, {{9, BLUE}, 34}, {{9, YELLOW}, 35}, {{9, RED}, 36},
    {{10, GREEN}, 37}, {{10, BLUE}, 38}, {{10, YELLOW}, 39}, {{10, RED}, 40},
    {{11, GREEN}, 41}, {{11, BLUE}, 42}, {{11, YELLOW}, 43}, {{11, RED}, 44},
    {{12, GREEN}, 45}, {{12, BLUE}, 46}, {{12, YELLOW}, 47}, {{12, RED}, 48},
    {{13, GREEN}, 49}, {{13, BLUE}, 50}, {{13, YELLOW}, 51}, {{13, RED}, 52}
};

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
        int value();

        /**
         * @brief Set the color of the card
         * 
         * @param color 
         */
        void setColor(Color color);

        /**
         * @brief Set the face value of the card
         * 
         * @param value 
         */
        void setValue(int value);
};

#endif