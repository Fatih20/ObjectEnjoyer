#include "../Ability.hpp"

class GameCandy;

class Quadruple : public Ability
{
public:
    Quadruple();
    void activateAbility(GameCandy &gC);
};