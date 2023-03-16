#include "DeckPlayer.hpp"

template <typename T>
DeckPlayer<T>::DeckPlayer(DeckGame<T> &drawnDeck, int numberOfCards) : Deck<T>()
{
    drawCard(drawnDeck, numberOfCards);
}

template <typename T>
DeckPlayer<T>::DeckPlayer(DeckPlayer<T> &other) : Deck<T>(other)
{
    this->vec = other.vec;
};

template <typename T>
DeckPlayer<T>::DeckPlayer() : Deck<T>()
{
}

template <typename T>
DeckPlayer<T>::DeckPlayer(std::vector<T> vec) : Deck<T>(vec)
{
    this->vec = vec;
};

template <typename T>
DeckPlayer<T>::~DeckPlayer(){};

template <typename T>
void DeckPlayer<T>::drawCard(DeckGame<T> &drawnDeck, int numberOfCards)
{
    for (int i = 0; i < numberOfCards; i++)
    {
        this->addCard(drawnDeck.ejectCard());
    }
};

template class DeckPlayer<ColorCard>;