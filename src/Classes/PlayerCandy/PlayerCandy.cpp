#include "PlayerCandy.hpp"

PlayerCandy::PlayerCandy(int id) : PlayerCandy()
{
    setGameID(id);
};

PlayerCandy::PlayerCandy(const PlayerCandy &p)
{
    Player(p);
    this->abilityUsed = p.abilityUsed;
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