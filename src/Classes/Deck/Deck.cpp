#include "Deck.hpp"
#include "Classes/Card/Card.hpp"

#include <vector>

template <typename T>
Deck<T>::Deck() {
    std::vector<T> vec;

    this->vec = vec;
}

template <typename T>
Deck<T>::Deck(std::vector<T> vec) {
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
void Deck<T>::shuffle(){
    
}

