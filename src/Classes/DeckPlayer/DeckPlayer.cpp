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
        this->vec.push_back(drawnDeck.ejectCard());
    }
};

template <typename T>
T DeckPlayer<T>::ejectCard()
{
    try{
        if(this->vec.size() <= 0)
            throw EmptyDeckException(); //untested

        T ejectedCard = this->vec.back();
        this->vec.pop_back();

        return ejectedCard;
    } catch(EmptyDeckException& e) {
        std::cout << e.what() << std::endl;
    }
};

template class DeckPlayer<ColorCard>;