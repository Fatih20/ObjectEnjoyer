#include "DeckPlayer.hpp"

template <typename T>
DeckPlayer<T>::DeckPlayer(const DeckGame<T> &other)
{
    for (int i = 0; i < 2; i++)
    { // may go generalizing it into "intended deck size"
        this->vec.insert(other.drawCard());
    }
}