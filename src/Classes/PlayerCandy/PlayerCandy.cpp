#include "PlayerCandy.hpp"

PlayerCandy::PlayerCandy(int id) : Player<ColorCard>(id){};

PlayerCandy::PlayerCandy(const PlayerCandy &p) : Player<ColorCard>(p)
{
    // this->abilityUsed = p.abilityUsed;
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