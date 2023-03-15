#include "PlayerCandy.hpp"
#include "../PlayerException/PlayerException.hpp"
#include "../GameCandy/GameCandy.hpp"

PlayerCandy::PlayerCandy(int id) : Player<ColorCard>(id){};

PlayerCandy::PlayerCandy(const PlayerCandy &p) : Player<ColorCard>(p)
{
    abilityUsed = p.abilityUsed;
    abilityHand = p.abilityHand;
}

PlayerCandy::PlayerCandy() : Player<ColorCard>(){};

void PlayerCandy::disableAbility()
{
    abilityUsed = true;
}

bool PlayerCandy::getAbilityAvailable()
{
    return !abilityUsed;
}

void PlayerCandy::drawAbility(DeckGame<AbilityCard> &deckAbility)
{
    this->abilityHand = deckAbility.ejectCard();
}

void PlayerCandy::useAbility(string abilityName, GameCandy &gC)
{
    if (abilityHand.getName() == abilityName)
    {
        abilityHand.activateAbility(gC);
    }
    else
    {
        AbilityNotOwned e;
        throw e;
    }
}

void PlayerCandy::useAbility(GameCandy &gC)
{
    abilityHand.activateAbility(gC);
}