#ifndef _ABILITYCARD_HPP_
#define _ABILITYCARD_HPP_

#include <memory>
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include <string>

using namespace std;

class AbilityCard : public Card<shared_ptr<Ability>>
{
private:
    // static BlankAbility blankAbility;

public:
    AbilityCard();
    /**
     * @brief Construct a new Ability Card object with given ability
     *
     * @param value The ability of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
     */
    // AbilityCard(Ability &ability);

    AbilityCard(shared_ptr<Ability> ability);

    ~AbilityCard();

    AbilityCard(const AbilityCard &aC);

    /**
     * @brief Get the value of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
     *
     * @return int
     */
    shared_ptr<Ability> value() const;

    /**
     * @brief Get the name of the ability
     *
     * @return std::string
     */
    string getName() const;

    /**
     * @brief Get the description of the card (for example, REROLL: reroll all hand cards)
     */
    string getDescription() const;

    /**
     * @brief Activate the ability of the card
     *
     */
    void activateAbility(GameCandy &gC);

    friend ostream &operator<<(std::ostream &os, const AbilityCard &card);
};

#endif