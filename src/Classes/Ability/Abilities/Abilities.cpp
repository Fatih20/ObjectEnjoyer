#include "Abilities.hpp"
#include "../../GameCandy/GameCandy.hpp"

Quadruple::Quadruple()
{
    abilityName = "QUADRUPLE";
    abilityDescription = "Quadruple the reward of the current round";
};

void Quadruple::activateAbility(GameCandy &gC)
{
    gC.quadruplePoint();
}