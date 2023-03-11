#include "Deck.hpp"
#include "Classes/Card/Card.hpp"

#include <vector>
#include <iostream>

template <typename T>
Deck<T>::Deck()
{
    std::vector<Card<T>> vec;

    this->vec = vec;
};

template <class T>
Deck<T>::Deck(std::vector<Card<T>> vec)
{
    this->vec = vec;
};

template <typename T>
Deck<T>::Deck(const Deck &other)
{
    this->vec = other.vec;
};

template <typename T>
Deck<T>::~Deck()
{
    this->vec.clear();
};

template <typename T>
void Deck<T>::swap(Deck &other)
{
    std::swap(this->vec, other.vec);
};

template <typename T>
void Deck<T>::shuffle(){};

template <typename T>
void Deck<T>::setDeck(std::vector<Card<T>> vec)
{
    this->vec = vec;
};

template <typename T>
std::vector<Card<T>> Deck<T>::getDeck()
{
    return this->vec;
};

template <class T>
void Deck<T>::swapDeck(Deck<T> &deck1, Deck<T> &deck2)
{
    std::swap(deck1.vec, deck2.vec);
};

// Need fixing

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const Deck<T> &deck)
// {
//     os << "\nsize : " << deck.vec.size() << "\nmembers : \n";

//     for (auto elmt : deck.vec)
//     {
//         os << elmt << " " << std::endl;
//     }

//     return os;
// };

template <typename T>
void Deck<T>::addToDeck(const Card<T> &card)
{
    vec.push_back(card); // havent considered whether the card should be in the very last position or the first
};

template class Deck<int>;
// template std::ostream &operator<<(std::ostream &os, const Deck<int> &deck);