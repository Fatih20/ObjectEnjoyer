#include "Card.hpp"

template <typename T>
Card<T>::Card(T value){
    this->value = value;
}

template <typename T>
T Card<T>::value(){
    return this->value;
}

template <typename T>
void Card<T>::setValue(T value){
    this->value = value;
}

template <typename T>
void Card<T>::operator=(const Card<T>& other){
    this->value = other.value;
}

template <typename T>
void swap(Card<T>& a, Card<T>& b){
    Card<T> temp = a;
    a = b;
    b = temp;
}