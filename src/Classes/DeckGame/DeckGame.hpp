#include <vector>
#include "Classes/Deck/Deck.hpp"
#include "Classes/Card/Card.hpp"

#ifndef _DECKGAME_HPP_
#define _DECKGAME_HPP_

// TODO : make this ABC
// ^put on hold
template <class T>
class DeckGame : public Deck<T>
{
public:
    /**
     * @brief construct new Game Deck with empty vector as its attribute
     */
    DeckGame();

    /**
     * @brief construct new Game Deck with a given value as its attribute
     *
     * @param vec array that will be set as the attribute of this Deck
     */
    DeckGame(std::vector<T> vec);

    /**
     * @brief construct new Game Deck based on an already constructed Deck
     *
     * @param other the other Deck
     */
    DeckGame(const Deck<T> &other);

    /**
     * @brief eject a card from this deck and return its value
     */
    T ejectCard();

    /**
     * @brief get the combination value of this deck against deckplayer
     */
    int getCombinationValueWith(const Deck<T> &deckPlayer) const; // NOTE: we use Deck as param to avoid circular dependency with DeckPlayer

};

#endif