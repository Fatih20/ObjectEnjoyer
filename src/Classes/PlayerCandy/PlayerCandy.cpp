#include "PlayerCandy.hpp"
#include "../PlayerException/PlayerException.hpp"
#include "../Combination/Combination.hpp"

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
    // cout << "Entered draw ability" << endl;
    // cout << "Initial ability" << endl
    //      << abilityHand.getName() << endl;
    // cout << "Deck ability cards amount before drawn " << deckAbility.getNumberOfCards() << endl;
    AbilityCard drawnCard = deckAbility.ejectCard();
    // cout << "Deck ability cards amount after drawn " << deckAbility.getNumberOfCards() << endl;
    // cout << "Cards drawn" << endl;
    // cout << "Drawn ability" << endl
    //      << drawnCard.getName() << endl;

    // bool success = false;
    // cout << "Entering try" << endl;
    abilityHand = drawnCard;
    // cout << "Exited draw ability" << endl
    //      << endl;
}

void PlayerCandy::useAbility(string abilityName, GameCandy &gC)
{
    if (abilityHand.getName() != abilityName)
    {
        AbilityNotOwned e;
        throw e;
    }

    if (!abilityUsed)
    {
        AbilityNotAvailable e;
        throw e;
    }

    abilityHand.activateAbility(gC);
}

void PlayerCandy::useAbility(GameCandy &gC)
{
    if (!abilityUsed)
    {
        AbilityNotAvailable e;
        throw e;
    }
    abilityHand.activateAbility(gC);
}

void PlayerCandy::test()
{
    abilityHand.value()->test();
}

bool PlayerCandy::higherCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame)
{
    return compareCombinationWeight(otherPlayer, deckGame) == 1;
};

bool PlayerCandy::equalCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame)
{
    return compareCombinationWeight(otherPlayer, deckGame) == 0;
};

bool PlayerCandy::lowerCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame)
{
    return compareCombinationWeight(otherPlayer, deckGame) == -1;
};

int PlayerCandy::compareCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame)
{
    Combination ourCombination((this->handCards), deckGame);
    Combination theirCombination((otherPlayer.handCards), deckGame);

    if (ourCombination > theirCombination)
    {
        return 1;
    }
    else if (ourCombination == theirCombination)
    {
        return 0;
    }
    else
    {
        return -1;
    }
};
