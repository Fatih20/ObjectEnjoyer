#include "PlayerException.hpp"

PlayerException::PlayerException()
{
    message = "";
}

string PlayerException::getMessage()
{
    return message;
}

UsernameEmpty::UsernameEmpty()
{
    message = "Username cannot be empty!";
};

AbilityNotOwned::AbilityNotOwned()
{
    message = "You don't have that ability!";
}
