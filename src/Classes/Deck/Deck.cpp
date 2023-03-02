#include "Deck.hpp"
#include "Classes/Card/Card.hpp"

#include <vector>
#include <iostream>

template <typename T>
Deck<T>::Deck() {
    std::vector<T> vec;

    this->vec = vec;
}

template <class T>
Deck<T>::Deck(std::vector<T> vec)
{
    this->vec = vec;
}

template <typename T>
Deck<T>::Deck(const Deck& other) {
    this->vec = other.vec;
}

template <typename T>
Deck<T>::~Deck() {
    this->vec.clear();
}

template <typename T>
void Deck<T>::swap(Deck& other) {
    std::vector<T> temp = this->vec;
    this->vec = other.vec;
    other.vec = temp;
}

template <typename T>
void Deck<T>::shuffle(){
    
}

template <typename T>
void Deck<T>::setDeck(std::vector<T> vec) {
    this->vec = vec;
}

template <typename T>
std::vector<T> Deck<T>::getDeck() {
    return this->vec;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Deck<T>& deck) {
    os <<   "\nsize : " << deck.vec.size() << 
            "\nmembers : \n";
    
    for(auto elmt : deck.vec) {
        os << elmt << " " << std::endl;
    }
}

template class Deck<int>;
template std::ostream& operator<< (std::ostream& os, const Deck<int>& deck);