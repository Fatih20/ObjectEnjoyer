#ifndef _ABILITYCARD_HPP_
#define _ABILITYCARD_HPP_

<<<<<<< HEAD
#include "../Classes/Card/Card.hpp"
=======
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
>>>>>>> 3a47d6f988be214a6d94afd0869ee2cf21530cb1
#include <string>

class AbilityCard : public Card<int>
{
public:
    /**
     * @brief Construct a new Ability Card object with given ability
     *
     * @param value The ability of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
     */
    AbilityCard(int ability);

    /**
     * @brief Get the value of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
     *
     * @return int
     */
    int value() const;

    /**
     * @brief Get the Ability of the card from integer conversion to enum
     *
     */
    Abi getAbility() const;

    /**
     * @brief Get the description of the card (for example, REROLL: reroll all hand cards)
     */
    std::string getDescription() const;

    /**
     * @brief Activate the ability of the card
     *
     */
    void activateAbility();

    friend std::ostream &operator<<(std::ostream &os, const AbilityCard &card);
};

#endif