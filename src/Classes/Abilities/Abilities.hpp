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
    void test() { /*cout << "Test quadruple" << endl;*/ };
};

class Quarter : public Ability
{
public:
    Quarter();
    Quarter(const Quarter &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test quarter" << endl;*/ };
};

class Reroll : public Ability
{
public:
    Reroll();
    Reroll(const Reroll &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test reroll" << endl;*/ };
};

class Reverse : public Ability
{
public:
    Reverse();
    Reverse(const Reverse &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test reverse" << endl;*/ };
};

class Swap : public Ability
{
public:
    Swap();
    Swap(const Swap &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test swap" << endl;*/};
};

class Switch : public Ability
{
public:
    Switch();
    Switch(const Switch &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test switch" << endl; */};
};

class Abilityless : public Ability
{
public:
    Abilityless();
    Abilityless(const Abilityless &q);
    void activateAbility(GameCandy &gC);
    void test() { /*cout << "Test abilityless" << endl;*/ };
};

#endif