#include "PlayerMini.hpp"
#include "../ColorCard/ColorCard.hpp"

template <typename T>
PlayerMini<T>::PlayerMini()
{
    username = "";
    score = 0;
}

template <typename T>
PlayerMini<T>::PlayerMini(string username, int score)
{
    this->username = username;
    this->score = score;
}

template <typename T>
PlayerMini<T>::PlayerMini(const Player<T> &p)
{
    this->username = p.getUsername();
    this->score = p.getScore();
}

template <typename T>
bool PlayerMini<T>::operator>(const PlayerMini<T> &p) const
{
    bool result = this->score > p.getScore();
    return result;
};

template <typename T>
unsigned int PlayerMini<T>::getScore() const
{
    return this->score;
};

template <typename T>
string PlayerMini<T>::getUsername() const
{
    return this->username;
};

template class PlayerMini<ColorCard>;
// template class PlayerMini<int>;