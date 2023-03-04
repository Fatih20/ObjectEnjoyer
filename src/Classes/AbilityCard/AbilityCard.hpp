#ifndef _ABILITYCARD_HPP_
#define _ABILITYCARD_HPP_

#include "Classes/Card/Card.hpp"
#include "Classes/Ability/Ability.hpp"
#include <string>

// waktu construct ambil value aja -> nanti description ambil dari enumnya 0-6 (di luar ini error)
// beberapa nilai diconstant aja

// OPERATOR OVERLOADING

class AbilityCard: public Card<int> {
    protected:
        int Ability;
        std::string description;
    
    public:
        /**
         * @brief Construct a new Ability Card object with given ability
         * 
         * @param value The ability of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
         */
        AbilityCard(int Ability);

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
         * @brief Activate the ability of the card
         * 
         */
        void activateAbility();
};

#endif