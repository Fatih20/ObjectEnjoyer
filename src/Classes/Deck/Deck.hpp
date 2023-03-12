#ifndef _DECK_HPP_
#define _DECK_HPP_

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include "../Card/Card.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

template <class T>
class Deck : InventoryHolder<T>
{
protected:
    /**
     * Deck holds a vector of cards
     *  How we interact with deck should follow these rules :
     *      - index with higher values should hold Card that is being on topmost of the Deck stack
     *      - Game should only be able to add Card to and/or draw from the topmost of the Deck stack
     */
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
    Deck(const Deck &other);

    /**
     * @brief destruct a constructed Deck
     */
    ~Deck();

    /**
     * @brief set a vector of cards as the content of Deck
     */
    void setDeck(std::vector<T> vec);

    /**
     * @brief get the cards contained by the Deck as a vector
     */
    std::vector<T> getDeck();

    /**
     * @brief Get the number of cards in this deck
     *
     * @return int
     */
    int getNumberOfCards();

    /**
     * @brief get the sum of the face values of all Cards held in this Deck
     */
     int getValueSum();

    /**
     * @brief add a card into the deck
     */
    void addCard(const T &);

    /**
     * @brief shorthand for addCard()
     */
    void operator+=(const T &);

    /**
     * @brief shorthand for addCard()
     */
    Deck<T>& operator<<(const T& card);

    /**
     * @brief Delete a card from the deck and then return it from this function
     *
     * @return T
     */
    T ejectCard();

    /**
     * @brief shorthand for ejectCard()
     *
     * return is void as we should not chain ejectCard()
     */
     void operator>>(Deck<T>& deck);

    /**
     * @brief sort deck by value
     */
    void sort();

    /**
     * @brief swap contents with another deck
     */
    void swap(Deck &other);

    /**
     * @brief swap the content of two separate Decks
     */
    static void swapDeck(Deck &deck1, Deck &deck2);

    /**
     * @brief shuffle deck
     */
    void shuffle();

    /**
     * @brief compare Card Value Sum (not necessarily true sum)
     * @return true if left operand has smaller sum
     * @return false if left operand has larger sum
     */
    bool operator< (const Deck<T>& other);

    /**
     * @brief compare Card Value Sum (not necessarily true sum)
     * @return true if both operand has the same sum
     * @return false if neither operand has the same sum
     */
    bool operator== (const Deck<T>& other);

    /**
     * @brief compare Card Value Sum (not necessarily true sum)
     * @return true if left operand has larger sum
     * @return false if left operand has smaller sum
     */
    bool operator> (const Deck<T>& other);

    /**
     * @brief add two Deck and return a new deck which consists of cards held by both Deck
     */
    Deck<T>& operator+(Deck<T>& other);


    /**
     * @brief print
     */
    template <typename Tc>
    friend std::ostream &operator<<(std::ostream &os, const Deck<Tc> &deck);
};

#endif