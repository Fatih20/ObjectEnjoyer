#include "Ability.hpp"

// const std::map<Abi, std::string> Ability::abilityDescription = {
//     {REROLL, "Reroll all hand cards"},
//     {QUADRUPLE, "Quadruple the reward of the current round"},
//     {QUARTER, "Quarter the reward of the current round"},
//     {REVERSE, "Reverse the order of the players"},
//     {SWAP, "Swap a card from the hand with a card from another player's hand"},
//     {SWITCH, "Switch the hand cards with another player's hand cards"},
//     {ABILITYLESS, "Disable the ability of a specific player"}};

// const std::map<Abi, std::string> Ability::abilityName = {
//     {REROLL, "Reroll"},
//     {QUADRUPLE, "Quadruple"},
//     {QUARTER, "Quarter"},
//     {REVERSE, "Reverse"},
//     {SWAP, "Swap"},
//     {SWITCH, "Switch"},
//     {ABILITYLESS, "Abilityless"}};

Ability::Ability()
{
    abilityName = "";
    abilityDescription = "";
    power = 0;
}

Ability::Ability(const Ability &ability)
{
    cout << "Ability ctor called" << endl;
    this->abilityName = ability.abilityName;
    this->abilityDescription = ability.abilityDescription;
    this->power = ability.power;
}

Ability &Ability::operator=(const Ability &ability)
{
    this->abilityName = ability.abilityName;
    this->abilityDescription = ability.abilityDescription;
    this->power = ability.power;
    return *this;
}

Ability::Ability(string name, string description, int power)
{
    abilityName = name;
    abilityDescription = description;
    this->power = power;
}

std::string Ability::getDescription()
{
    return abilityDescription;
}

std::string Ability::getName()
{
    return abilityName;
}

bool Ability::operator<=(const Ability &ability) { return this->power <= ability.power; }

bool Ability::operator==(const Ability &ability) { return this->power == ability.power; }

bool Ability::operator>=(const Ability &ability) { return this->power >= ability.power; }

bool Ability::operator>(const Ability &ability) { return this->power > ability.power; }

bool Ability::operator<(const Ability &ability) { return this->power < ability.power; }

bool Ability::operator!=(const Ability &ability) { return this->power != ability.power; }
// Ability &Ability::operator=(const Ability &ability) : Ability(ability){
//                                                           return *this};

std::ostream &operator<<(std::ostream &os, const Ability &ability)
{
    os << ability.abilityName << " " << ability.abilityDescription;
    return os;
};

// bool Ability::operator<=(const Ability &ability) { return this->power > ability.power; }
