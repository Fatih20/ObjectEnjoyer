#include "Ability.hpp"

const std::map<Abi, std::string> abilityDescription = {
    {REROLL, "Reroll all hand cards"},
    {QUADRUPLE, "Quadruple the reward of the current round"},
    {QUARTER, "Quarter the reward of the current round"},
    {REVERSE, "Reverse the order of the players"},
    {SWAP, "Swap a card from the hand with a card from another player's hand"},
    {SWITCH, "Switch the hand cards with another player's hand cards"},
    {ABILITYLESS, "Disable the ability of a specific player"}
};

Ability::Ability(Abi ability){
    this->ability = ability;
    this->description = abilityDescription.at(ability);
}

Abi Ability::getAbility(){
    return this->ability;
}

std::string Ability::getDescription(){
    return this->description;
}