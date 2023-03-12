#ifndef _COLORCARD_HPP_
#define _COLORCARD_HPP_

#include "../Card/Card.hpp"
#include <map>
#include <utility>

typedef enum
{
    GREEN,
    BLUE,
    YELLOW,
    RED
} Color;

class ColorCard : public Card<int>
{
protected:
    Color color;
    static const std::map<std::pair<int, Color>, int> cardWeight;

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
         * @brief Get the Face Value of the card
         * 
         */
        int getNumber();

        /**
         * @brief Get the card weight based on the value and color relative to other color cards
         * 
         */
        virtual int value();

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
    void setValue(int value, Color color);

    /**
     * @brief Assign the value and color of another color card to this color card
     *
     */
    virtual void operator=(const ColorCard &other);

    /**
     * @brief Compare if two color cards have the same value and color
     *
     */
    bool operator==(ColorCard other);

    friend std::ostream &operator<<(std::ostream &os, const ColorCard &card);
        /**
         * @brief Compare if two color cards have the same value and color
         * 
         */
        bool operator==(ColorCard other);

        friend bool operator<(ColorCard a, ColorCard b);

        friend bool operator>(ColorCard a, ColorCard b);

        void print();
};

/**
 * @brief Swap two color cards
 *
 */
void swap(ColorCard &a, ColorCard &b);

#endif