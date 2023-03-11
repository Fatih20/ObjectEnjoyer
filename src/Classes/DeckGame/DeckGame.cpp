#include "DeckGame.hpp"

#include <vector>

template <typename T>
DeckGame<T>::DeckGame() : Deck<T>::Deck(){}; // actually redundant?

template <class T>
DeckGame<T>::DeckGame(std::vector<Card<T>> vec) : Deck<T>::Deck(vec){};

template <typename T>
DeckGame<T>::DeckGame(const DeckGame &other) : Deck<T>::Deck(other) {}

template <typename T>
Card<T> DeckGame<T>::drawCard()
{
    Card<T> res = this->vec.back();

    this->vec.pop_back();

    return res;
}

template <typename T>
int DeckGame<T>::getCombinationValueWith(const Deck<T> &deckPlayer)
{
}

template Card<int> DeckGame<int>::drawCard();
template class DeckGame<int>;
