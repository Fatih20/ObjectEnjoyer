#include "PlayerCandy.hpp"

PlayerCandy::PlayerCandy(int id) : Player<ColorCard>(id){};

PlayerCandy::PlayerCandy(const PlayerCandy &p) : Player<ColorCard>(p)
{
    Player(p);
    this->abilityUsed = p.abilityUsed;
    abilityHand = p.abilityHand;
}

PlayerCandy::PlayerCandy() : Player<ColorCard>(){};

void PlayerCandy::disableAbility()
{
    abilityUsed = false;
}

bool PlayerCandy::getAbilityAvailable()
{
    return abilityUsed;
}