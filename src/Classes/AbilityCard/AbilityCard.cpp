#include "AbilityCard.hpp"

AbilityCard::AbilityCard(int ability) : Card<int>(ability){}

Abi AbilityCard::getAbility(){
    return Abi(value());
}

std::string AbilityCard::getDescription(){
    return Ability(this->getAbility()).getDescription();
}

void AbilityCard::activateAbility(){
    Ability temp(this->getAbility());
    temp.activateAbility();
}

int AbilityCard::value(){
    return this->Card::val;
}