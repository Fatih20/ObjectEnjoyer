#ifndef _DECKGAME_HPP_
#define _DECKGAME_HPP_

#include "Classes/Deck/Deck.hpp"
#include "Classes/Card/Card.hpp"

template <typename T>
class DeckGame: public Deck {
    public:
        /**
         * @brief construct new Game Deck with empty array as its attribute
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
        DeckGame(int size, int maxSize);

        /**
         * @brief construct new Game Deck with a given value as its attribute
         * 
         * @param value array that will be set as the attribute of this Deck
         * @param size current size of the deck
         * @param maxSize maximum size of the deck
        */
       DeckGame(Card<T>* value, int size, int maxSize);

        /**
         * @brief construct new Game Deck based on an already constructed Deck
         * 
         * @param other the other Deck
        */
       DeckGame(const DeckGame& other);

        /**
         * @brief destruct constructed Deck
        */
       ~DeckGame();

        /**
         * @brief draw a card from this deck
        */
        Card DrawCard();
};

#endif