#ifndef _DECK_GAME_CANGKUL_HPP_
#define _DECK_GAME_CANGKUL_HPP_

#include "../DeckGame/DeckGame.hpp"
#include "../ColorCard/ColorCard.hpp"

class DeckGameCangkul : public DeckGame<ColorCard>{
    public:
        /**
         * @brief Construct a new Deck Game Cangkul object with empty vector as its attribute
         * 
         */
        DeckGameCangkul();

        /**
         * @brief Construct a new Deck Game Cangkul object from a vector of ColorCard
         * 
         */
        DeckGameCangkul(std::vector<ColorCard> vec);

        /**
         * @brief Construct a new Deck Game Cangkul object from another DeckGameCangkul
         * 
         */
        DeckGameCangkul(const DeckGameCangkul &other);

        /**
         * @brief Check whether a color exists in the deck
         * 
         */
        bool isThereColor(Color color);
};

#endif