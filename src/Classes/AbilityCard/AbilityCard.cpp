#include "AbilityCard.hpp"

AbilityCard::AbilityCard(int ability) : Card<int>(ability) {}

Abi AbilityCard::getAbility() const
{
    return Abi(value());
}

std::string AbilityCard::getDescription() const
{
    return Ability(this->getAbility()).getDescription();
}

void AbilityCard::activateAbility()
{
    Ability temp(this->getAbility());
    temp.activateAbility();
}

int AbilityCard::value() const
{
    return this->Card::val;
}

std::ostream &operator<<(std::ostream &os, const AbilityCard &card)
{
    os << card.val << " " << card.getDescription();
    return os;
}
