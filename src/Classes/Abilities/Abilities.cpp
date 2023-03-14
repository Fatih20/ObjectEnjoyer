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