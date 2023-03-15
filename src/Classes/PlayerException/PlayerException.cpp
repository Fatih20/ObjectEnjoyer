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
    message = "Ets, tidak bisa. Kamu tidak punya kartu Ability ";
}

AbilityNotAvailable::AbilityNotAvailable()
{
    message = "Oops, kartu abilitymu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.";
}
