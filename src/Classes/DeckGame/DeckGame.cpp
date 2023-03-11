#include "DeckGame.hpp"

#include <vector>

template <typename T>
DeckGame<T>::DeckGame() : Deck<T>::Deck(){}; // actually redundant?

template <class T>
DeckGame<T>::DeckGame(std::vector<T> vec) : Deck<T>::Deck(vec){};

template <typename T>
DeckGame<T>::DeckGame(const DeckGame<T> &other) : Deck<T>::Deck(other) {}

template <typename T>
T DeckGame<T>::drawCard()
{
    T res = this->vec.back();

    this->vec.pop_back();

    return res;
}

template <typename T>
int DeckGame<T>::getCombinationValueWith(const Deck<T> &deckPlayer)
{
    return 0;
}

// template class DeckGame<Card<int>>;
// template Card<int> DeckGame<Card<int>>::drawCard();
