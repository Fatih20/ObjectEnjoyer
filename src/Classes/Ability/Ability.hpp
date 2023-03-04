#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <map>

typedef enum{
    REROLL, // Reroll all hand cards
    QUADRUPLE, // Quadruple the reward of the current round
    QUARTER, // Quarter the reward of the current round
    REVERSE, // Reverse the order of the players
    SWAP, // Swap a card from the hand with a card from another player's hand
    SWITCH, // Switch the hand cards with another player's hand cards
    ABILITYLESS // Disable the ability of a specific player
} Abi;

extern const std::map<Abi, std::string> abilityDescription;

class Ability {
    private:
        Abi ability;
        std::string description;
    
    public:
        /**
         * @brief Construct a new Ability object with given ability
         * 
         * @param ability The ability of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
         */
        Ability(Abi ability);

        /**
         * @brief Get the Ability of the card from integer conversion to enum
         * 
         */
        Abi getAbility();

        /**
         * @brief Get the description of the card (for example, REROLL: reroll all hand cards)
         */
        std::string getDescription();

        /**
         * @brief Activate the ability
         * 
         */
        virtual void activateAbility() = 0;
};

#endif