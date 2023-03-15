#include "AbilityCard.hpp"

// BlankAbility AbilityCard::blankAbility = *(new BlankAbility());

AbilityCard::AbilityCard() : Card<shared_ptr<Ability>>(shared_ptr<Ability>(new BlankAbility()))
{
}

AbilityCard::~AbilityCard(){
    // cout << "Destructor called" << endl;
    // delete val;
};

// AbilityCard::AbilityCard(Ability *abilityPointer) : Card<shared_ptr<Ability>>(make_shared<Ability>(abilityPointer))
// {
// }

AbilityCard::AbilityCard(shared_ptr<Ability> abilityPointer) : Card<shared_ptr<Ability>>(abilityPointer)
{
}

// AbilityCard::AbilityCard(Ability &ability) : Card<shared_ptr<Ability>>(make_shared<Ability>(&ability))
// {
//     // *val = *(&ability);
// }

AbilityCard::AbilityCard(const AbilityCard &aC) : Card<shared_ptr<Ability>>(aC.value())
{
    // *val = *(aC.val);
}

string AbilityCard::getName() const
{
    return value()->getName();
}

string AbilityCard::getDescription() const
{
    return value()->getDescription();
}

void AbilityCard::activateAbility(GameCandy &gC)
{
    value()->activateAbility(gC);
}

shared_ptr<Ability> AbilityCard::value() const
{
    return val;
}

ostream &operator<<(std::ostream &os, const AbilityCard &card)
{
    os << card.getName() << " " << card.getDescription();
    return os;
}
