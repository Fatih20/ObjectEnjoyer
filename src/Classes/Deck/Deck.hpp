#ifndef _DECK_HPP_
#define _DECK_HPP_

#include "Classes/Card/Card.hpp"

template <typename T>
class Deck {
    protected:
        Card<T>* array;

        int maxSize;
        int size;

    public:
        /**
         * @brief construct new Deck with empty array as its attribute
         * 
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
        Deck(int size, int maxSize);

        /**
         * @brief construct new Deck with a given value as its attribute
         * 
         * @param value array that will be set as the attribute of this Deck
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
       Deck(Card<T>* value, int size, int maxSize);

        /**
         * @brief construct new Deck based on an already constructed Deck
         * 
         * @param other the other Deck
        */
       Deck(const Deck& other);

        /**
         * @brief destruct a constructed Deck
        */
       ~Deck();

        /**
         * @brief swap contents with another deck
        */
       void Swap(Deck& other);
};

#endif