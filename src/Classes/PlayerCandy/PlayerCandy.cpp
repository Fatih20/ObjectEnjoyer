#include "PlayerCandy.hpp"
#include "../PlayerException/PlayerException.hpp"
#include "../GameCandy/GameCandy.hpp"

PlayerCandy::PlayerCandy(int id) : Player<ColorCard>(id){};

PlayerCandy::PlayerCandy(int id, DeckGame<AbilityCard> &deckGame) : Player<ColorCard>(id)
{
    drawAbility(deckGame);
    // this->abilityHand = deckGame.ejectCard();
};

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

string PlayerCandy::getAbilityName()
{
    return abilityHand.getName();
}

bool PlayerCandy::getAbilityAvailable()
{
    return !abilityUsed;
}

void PlayerCandy::drawAbility(DeckGame<AbilityCard> &deckAbility)
{
    cout << "Entered draw ability" << endl;
    AbilityCard drawnCard = deckAbility.ejectCard();
    cout << "Cards drawn" << endl;
    bool success = false;
    while (!success)
    {

        try
        {
            this->abilityHand = drawnCard;

            success = true;
        }
        catch (bad_alloc e)
        {
        }
    }
    cout << "Exited draw ability" << endl;
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