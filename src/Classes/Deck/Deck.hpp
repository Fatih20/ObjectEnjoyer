#ifndef _DECK_HPP_
#define _DECK_HPP_

template <typename T>
class Deck {
    protected:
        T* array;

    public:
        /**
         * @brief construct new Deck with empty array as its attribute
        */
        Deck();

        /**
         * @brief construct new Deck with a given value as its attribute
         * 
         * @param value array that will be set as the attribute of this Deck
        */
       Deck(T* value);

        /**
         * @brief construct new Deck based on an already constructed Deck
         * 
         * @param other the other Deck
        */
       Deck(const Deck& other);

        /**
         * @brief destruct constructed Deck
        */
       ~Deck();
};

#endif