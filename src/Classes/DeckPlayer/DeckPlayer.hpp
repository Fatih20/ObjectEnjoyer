#ifndef _DECKPLAYER_HPP_
#define _DECKPLAYER_HPP_

#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/Card/Card.hpp"
#include "Classes/ColorCard/ColorCard.hpp"

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

    // /**
    //  * @brief compare the combination value of two Decks
    //  *
    //  * @return true Left player has worse combination
    //  * @return false Left player has better combination
    // */
    // bool operator<(const DeckPlayer&);

    // /**
    //  * @brief compare the combination value of two Decks
    //  *
    //  * @return true Left player has better combination
    //  * @return false Left player has worse combination
    // */
    // bool operator>(const DeckPlayer&);

    // /**
    //  * @brief compare the combination value of two Decks
    //  *
    //  * @return true Both players have the same combination value
    //  * @return false The two players have different value of cards combination
    // */
    // bool operator==(const DeckPlayer&);

    // /**
    //  * @brief compare the combination value of two Decks
    //  *
    //  * @return true Left player has worse if not the same value of cards combination
    //  * @return false Left player has better combination
    // */
    // bool operator<=(const DeckPlayer&);

    // /**
    //  * @brief compare the combination value of two Decks
    //  *
    //  * @return true Left player has better if not the same value of cards combination
    //  * @return false Left player has worse combination
    // */
    // bool operator>=(const DeckPlayer&);
};

#endif