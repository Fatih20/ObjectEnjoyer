#ifndef _DECKPLAYER_HPP_
#define _DECKPLAYER_HPP_

#include "../Deck/Deck.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "../Card/Card.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../DeckException/DeckException.hpp"

template <class T>
class DeckPlayer : public Deck<T>
{

public:
    /**
     * @brief construct a DeckPlayer whose content is made of cards drawn from DeckGame
     */
    DeckPlayer(DeckPlayer<T> &);
    /**
     * @brief construct new Player Deck with empty array as its attribute
     */
    DeckPlayer();

    /**
     * @brief construct new Player Deck with a given array as its attribute
     * @param vec array that will be set as the attribute of this Deck
     */
    DeckPlayer(std::vector<T> vec);

    /**
     * @brief construct new Player Deck with cards drawn from an already constructed Deck
     *
     * @param other the other Deck
     */
    DeckPlayer(DeckGame<T> &other, int numberOfCards);

    /**
     * @brief destruct constructed Player Deck
     */
    ~DeckPlayer();

    /**
     * @brief Draw a number of cards from the deck game
     *
     */
    void drawCard(DeckGame<T> &, int);

    /**
     * @brief Delete a card from the deck and then return it from this function
     *
     * @return T
     */
    T ejectCard();
};

#endif