#include "Card.hpp"

template <typename T>
Card<T>::Card(T value){
    this->val = value;
}

template <typename T>
T Card<T>::value(){
    return this->val;
}

template <typename T>
void Card<T>::setValue(T value){
    this->val = value;
}

template <typename T>
void Card<T>::operator=(const Card<T>& other){
    this->val = other.value;
}

template <typename T>
void swap(Card<T>& a, Card<T>& b){
    Card<T> temp = a;
    a = b;
    b = temp;
}