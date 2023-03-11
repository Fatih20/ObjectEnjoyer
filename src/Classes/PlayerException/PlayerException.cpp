#include "PlayerException.hpp"

UsernameEmpty::UsernameEmpty()
{
    message = "Username cannot be empty!";
};

string UsernameEmpty::getMessage()
{
    return message;
}