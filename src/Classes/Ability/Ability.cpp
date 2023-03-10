#include "Ability.hpp"

const std::map<Abi, std::string> Ability::abilityDescription = {
    {REROLL, "Reroll all hand cards"},
    {QUADRUPLE, "Quadruple the reward of the current round"},
    {QUARTER, "Quarter the reward of the current round"},
    {REVERSE, "Reverse the order of the players"},
    {SWAP, "Swap a card from the hand with a card from another player's hand"},
    {SWITCH, "Switch the hand cards with another player's hand cards"},
    {ABILITYLESS, "Disable the ability of a specific player"}
};

const std::map<Abi, std::string> Ability::abilityName = {
    {REROLL, "Reroll"},
    {QUADRUPLE, "Quadruple"},
    {QUARTER, "Quarter"},
    {REVERSE, "Reverse"},
    {SWAP, "Swap"},
    {SWITCH, "Switch"},
    {ABILITYLESS, "Abilityless"}
};

Ability::Ability(Abi ability){
    this->ability = ability;
}

Abi Ability::getAbility(){
    return this->ability;
}

std::string Ability::getDescription(){
    return abilityDescription.at(this->ability);
}

std::string Ability::getAbilityName(){
    return abilityName.at(this->ability);
}