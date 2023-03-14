#ifndef _ABILITIES_HPP_
#define _ABILITIES_HPP_
#include "../Ability/Ability.hpp"

class GameCandy;

class Quadruple : public Ability
{
public:
    Quadruple();
    Quadruple(const Quadruple &q);

    void activateAbility(GameCandy &gC);
};

class Quarter : public Ability
{
public:
    Quarter();
    Quarter(const Quarter &q);
    void activateAbility(GameCandy &gC);
};

#endif