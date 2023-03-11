#include "Classes/DeckPlayer/DeckPlayer.hpp"

template <typename T>
DeckPlayer<T>::DeckPlayer(Deck<T> &deckGame)
{
    for (int i = 0; i < 2; i++)
    { // may go generalizing it into "intended deck size"
        this->vec.insert(deckGame.drawCard());
    }
}