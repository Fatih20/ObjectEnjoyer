#include "Classes/DeckPlayer/DeckPlayer.hpp"

template <typename T>
DeckPlayer<T>::DeckPlayer(DeckGame<T> &drawnDeck, int numberOfCards) : Deck<T>()
{
    drawCard(drawnDeck, numberOfCards);
}

template <typename T>
DeckPlayer<T>::DeckPlayer(DeckPlayer<T> &other)
{
    this->vec = other.vec;
};

template <typename T>
DeckPlayer<T>::DeckPlayer() : Deck<T>()
{
}

template <typename T>
DeckPlayer<T>::DeckPlayer(std::vector<T> vec)
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
        this->vec.push_back(drawnDeck.drawCard());
    }
};

template <typename T>
T DeckPlayer<T>::ejectCard()
{
    if (this->vec.size() != 0)
    {
        // Seharusnya work just fine. But kalau ada misal ada masalah bisa look into this
        T ejectedCard = this->vec.back();
        this->vec.pop_back();
        return ejectedCard;
    }
    else
    {
        // Mestinya throw exception
    }
};
template class DeckPlayer<ColorCard>;