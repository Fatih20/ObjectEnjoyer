#include "Deck.hpp"
#include "../Card/Card.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../AbilityCard/AbilityCard.hpp"

#include <vector>
#include <iostream>

template <typename T>
Deck<T>::Deck()
{
    std::vector<T> vec;

    this->vec = vec;
};

template <class T>
Deck<T>::Deck(std::vector<T> vec)
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
void Deck<T>::shuffle(){
    std::default_random_engine rng;
    rng.seed(time(0));

    std::shuffle(this->vec.begin(), this->vec.end(), rng);
};

template <typename T>
void Deck<T>::setDeck(std::vector<T> vec)
{
    this->vec = vec;
};

template <typename T>
std::vector<T> Deck<T>::getDeck()
{
    return this->vec;
};

template <class T>
void Deck<T>::swapDeck(Deck<T> &deck1, Deck<T> &deck2)
{
    std::swap(deck1.vec, deck2.vec);
};

// Need fixing

template <typename T>
std::ostream &operator<<(std::ostream &os, const Deck<T> &deck)
{
    os << "\nsize : " << deck.vec.size() << "\nmembers : \n";

    for (auto elmt : deck.vec)
    {
        os << elmt << " " << std::endl;
    }

    return os;
};

template <typename T>
void Deck<T>::addCard(const T &card)
{
    this->vec.push_back(card); // havent considered whether the card should be in the very last position or the first
};

template <typename T>
void Deck<T>::operator+=(const T &card)
{
    this->addCard(card);
};

template <typename T>
int Deck<T>::getNumberOfCards()
{
    return this->vec.size();
};

template<typename T>
void Deck<T>::sort() {
    std::sort(this->vec.begin(), this->vec.end(), [](T a, T b){ // sementara exclusive ColorCard
        return a.value() < b.value();
    });
}

template class Deck<Card<int>>;
template class Deck<ColorCard>;
template class Deck<AbilityCard>;
template std::ostream &operator<<(std::ostream &os, const Deck<Card<int>> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<ColorCard> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<AbilityCard> &deck);