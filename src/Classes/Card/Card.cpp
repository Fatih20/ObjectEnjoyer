#include "Card.hpp"
#include "../Ability/Ability.hpp"

template <typename T>
Card<T>::Card(T value) : val(value){
                             // val = value;
                         };

template <typename T>
T Card<T>::value() const
{
    return val;
}

template <typename T>
void Card<T>::setValue(T value)
{
    val = value;
}

template <typename T>
Card<T>::Card(const Card<T> &other) : val(other.val){
                                          // val = other.val;
                                      };

template <typename T>
Card<T> &Card<T>::operator=(const Card<T> &other)
{
    val = other.val;
    return *this;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Card<T> &card)
{
    os << card.value();

    return os;
}

template class Card<int>;
template class Card<Ability &>;
template std::ostream &operator<<(std::ostream &os, const Card<int> &card);
