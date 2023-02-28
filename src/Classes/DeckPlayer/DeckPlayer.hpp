#ifndef _DECKPLAYER_HPP_
#define _DECKPLAYER_HPP_

#include "Classes/Deck/Deck.hpp"
#include "Classes/Card/Card.hpp"

template <class T>
class DeckPlayer: public Deck {
    
    public:
        /**
         * @brief construct new Player Deck with empty array as its attribute
        */
        DeckPlayer();

        /**
         * @brief construct new Player Deck with a given array as its attribute
         * @param vec array that will be set as the attribute of this Deck
        */
        DeckPlayer(std::vector<Card<T>> vec);

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