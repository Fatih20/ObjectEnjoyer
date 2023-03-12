#include "Deck.hpp"
#include "Classes/Card/Card.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include "Classes/AbilityCard/AbilityCard.hpp"
#include "Classes/DeckException/DeckException.hpp"

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
void Deck<T>::setDeck(std::vector<T> vec)
{
    this->vec = vec;
};

template <typename T>
std::vector<T> Deck<T>::getDeck()
{
    return this->vec;
};

template <typename T>
int Deck<T>::getNumberOfCards()
{
    return this->vec.size();
};

//template <typename T>
//int Deck<T>::getValueSum() {
//    int sum = 0;
//
//    for (auto card : this->vec) {
//        sum += card.value();
//    }
//
//    return sum;
//}

template <typename T>
void Deck<T>::addCard(const T &card)
{
    this->vec.push_back(card);
};

template <typename T>
void Deck<T>::operator+=(const T &card)
{
    this->addCard(card);
};

template <typename T>
Deck<T>& Deck<T>::operator<<(const T& card) {
    addCard(card);

    return *this;
}

template <typename T>
T Deck<T>::ejectCard() {
    try{
        if(this->vec.size() <= 0)
            throw EmptyDeckException(); //untested

        T ejectedCard = this->vec.back();
        this->vec.pop_back();

        return ejectedCard;
    } catch(EmptyDeckException& e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void Deck<T>::operator>>(Deck<T> &deck) {
    deck.addCard(this->ejectCard());
}

//TODO: implement polymorphism
template<typename T>
void Deck<T>::sort() {
    std::sort(this->vec.begin(), this->vec.end(), [](T a, T b){
        return a.value() > b.value();
    });
}

template <typename T>
void Deck<T>::swap(Deck &other)
{
    std::swap(this->vec, other.vec);
};

template <class T>
void Deck<T>::swapDeck(Deck<T> &deck1, Deck<T> &deck2)
{
    std::swap(deck1.vec, deck2.vec);
};

template <typename T>
void Deck<T>::shuffle(){
    std::default_random_engine rng;
    rng.seed(time(0));

    std::shuffle(this->vec.begin(), this->vec.end(), rng);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Deck<T> &deck)
{
    os << "\nsize : " << deck.vec.size() << "\nmembers : \n";

    int i = 1;
    for (auto elmt : deck.vec)
    {
        os << i << ". " << elmt;
        i++;
    }

    return os;
};

template class Deck<Card<int>>;
template class Deck<ColorCard>;
template class Deck<AbilityCard>;
template std::ostream &operator<<(std::ostream &os, const Deck<Card<int>> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<ColorCard> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<AbilityCard> &deck);