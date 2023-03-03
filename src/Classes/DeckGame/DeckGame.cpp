#include "DeckGame.hpp"

#include <vector>

template <typename T>
DeckGame<T>::DeckGame() : Deck() {}

template <typename T>
DeckGame<T>::DeckGame(std::vector<T> vec) : Deck(vec) {}

template <typename T>
DeckGame<T>::DeckGame(const DeckGame& other) : Deck(other) {}

template <typename T>
T DeckGame<T>::drawCard() {
    T res  = this->vec.back();

    this->vec.pop_back();

    return res;
}

