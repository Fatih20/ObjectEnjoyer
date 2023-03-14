#include "Abilities.hpp"
#include "../../GameCandy/GameCandy.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE", "Quadruple the reward of the current round", 1){};

void Quadruple::activateAbility(GameCandy &gC)
{
    gC.quadruplePoint();
}

Quarter::Quarter() : Ability("QUARTER", "Quarter the reward of the current round", 1){};

void Quarter::activateAbility(GameCandy &gC)
{
    gC.quarterPoint();
}