#include "Card.hpp"

template <typename T>
Card<T>::Card(T value){
    this->value = value;
}

template <typename T>
void Card<T>::operator=(const Card<T>& other){
    this->value = other.value;
}

template <typename T>
void swap(Card<T>& a, Card<T>& b){
    T temp = a.value;
    a.value = b.value;
    b.value = temp;
}