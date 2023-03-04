#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include "../Card/Card.hpp"
#include <Map>
#include <utility>

typedef enum{
    GREEN,
    BLUE,
    YELLOW,
    RED
} Color;

// nanti pindahkan ke cpp
extern const std::map<std::pair<int, Color>, int> cardWeight;

class ColorCard: public Card<int> {
    protected:
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