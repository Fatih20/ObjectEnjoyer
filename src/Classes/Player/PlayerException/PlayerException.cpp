#include "PlayerException.hpp"

UsernameExist::UsernameExist(string notUniqueUsername)
{
    this->notUniqueUsername = notUniqueUsername;
}

string UsernameExist::getUsernameThatExist()
{
    return this->notUniqueUsername;
}

UsernameEmpty::UsernameEmpty(){

};