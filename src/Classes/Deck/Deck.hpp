#ifndef _DECK_HPP_
#define _DECK_HPP_

#include <vector>
// #include "Classes/Card/Card.hpp"

template <class T>
class Deck {
    protected:
        std::vector<T> vec;

    public:
        /**
         * @brief construct new Deck with empty vector as its attribute
        */
        Deck();

        /**
         * @brief construct new Deck with a given value as its attribute
         * 
         * @param vec vector that will be set as the attribute of this Deck
        */
       Deck(std::vector<T> vec);

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
       void swap(Deck& other);

        /**
         * @brief shuffle deck
        */
       void shuffle();
};

#endif