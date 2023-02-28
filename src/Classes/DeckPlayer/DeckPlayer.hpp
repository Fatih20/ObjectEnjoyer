#ifndef _DECKPLAYER_HPP_
#define _DECKPLAYER_HPP_

#include "Classes/Deck/Deck.hpp"
#include "Classes/Card/Card.hpp"

template <typename T>
class DeckPlayer: public Deck {
    
    public:
        /**
         * @brief construct new Player Deck with empty array as its attribute
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
        DeckPlayer(int size, int maxSize);

        /**
         * @brief construct new Player Deck with a given array as its attribute
         * @param value array that will be set as the attribute of this Deck
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
        DeckPlayer(Card<T>* value, int size, int maxSize);

        /**
         * @brief construct new Player Deck based on an already constructed Deck
         * 
         * @param other the other Deck
        */
        DeckPlayer(const DeckPlayer& other);

        /**
         * @brief destruct constructed Player Deck
        */
        ~DeckPlayer();
};

#endif