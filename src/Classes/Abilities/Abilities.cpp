#include "Abilities.hpp"
#include "../GameCandy/GameCandy.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE", "Quadruple the reward of the current round", 1){};

Quadruple::Quadruple(const Quadruple &q) : Ability(q){};

void Quadruple::activateAbility(GameCandy &gC)
{
    gC.quadruplePoint();
}

Quarter::Quarter() : Ability("QUARTER", "Quarter the reward of the current round", 1){};

Quarter::Quarter(const Quarter &q) : Ability(q){};

void Quarter::activateAbility(GameCandy &gC)
{
    gC.quarterPoint();
}

Reroll::Reroll() : Ability("REROLL", "Reroll all hand cards of this player", 2){};

Reroll::Reroll(const Reroll &q) : Ability(q){};

void Reroll::activateAbility(GameCandy &gC)
{
    gC.rerollAbility();
}

Reverse::Reverse() : Ability("REVERSE", "Reverse the order of the players", 2){};

Reverse::Reverse(const Reverse &q) : Ability(q){};

void Reverse::activateAbility(GameCandy &gC)
{
    gC.reverseAbility();
}

Swap::Swap() : Ability("SWAP", "Swap a card from the hand with a card from another player's hand", 2){};

Swap::Swap(const Swap &q) : Ability(q){};

void Swap::activateAbility(GameCandy &gC)
{
    gC.swapAbility();
}

Switch::Switch() : Ability("SWITCH", "Switch the hand cards with another player's hand cards", 2){};

Switch::Switch(const Switch &q) : Ability(q){};

void Switch::activateAbility(GameCandy &gC)
{
    gC.switchAbility();
}

Abilityless::Abilityless() : Ability("ABILITYLESS", "Disable the ability of a specific player", 3){};

Abilityless::Abilityless(const Abilityless &q) : Ability(q){};

void Abilityless::activateAbility(GameCandy &gC)
{
    gC.abilitylessAbility();
}