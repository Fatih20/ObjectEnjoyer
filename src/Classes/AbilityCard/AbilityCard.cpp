#include "AbilityCard.hpp"

AbilityCard::AbilityCard(Ability &ability) : Card<Ability &>(ability)
{
}

AbilityCard::AbilityCard(const AbilityCard &aC) : Card<Ability &>(aC)
{
}

std::string AbilityCard::getName() const
{
    return value().getName();
}

std::string AbilityCard::getDescription() const
{
    return value().getDescription();
}

void AbilityCard::activateAbility(GameCandy &gC)
{
    value().activateAbility(gC);
}

Ability &AbilityCard::value() const
{
    return val;
}

std::ostream &operator<<(std::ostream &os, const AbilityCard &card)
{
    os << card.val << " " << card.getDescription();
    return os;
}
