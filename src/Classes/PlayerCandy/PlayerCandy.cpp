#include "PlayerCandy.hpp"
#include "../PlayerException/PlayerException.hpp"
#include "../Combination/Combination.hpp"

PlayerCandy::PlayerCandy(int id) : Player<ColorCard>(id)
{
    abilityUsed = false;
    abilityLessVictim = false;
};

PlayerCandy::PlayerCandy(int id, DeckGame<AbilityCard> &deckGame) : Player<ColorCard>(id)
{
    drawAbility(deckGame);
    abilityUsed = false;
    abilityLessVictim = false;
};

PlayerCandy::PlayerCandy(const PlayerCandy &p) : Player<ColorCard>(p)
{
    abilityUsed = p.abilityUsed;
    abilityHand = p.abilityHand;
    abilityLessVictim = p.abilityLessVictim;
}

PlayerCandy::PlayerCandy() : Player<ColorCard>()
{
    abilityUsed = false;
    abilityLessVictim = false;
};

void PlayerCandy::disableAbility()
{
    abilityUsed = true;
    abilityLessVictim = true;
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
    AbilityCard drawnCard = deckAbility.ejectCard();
    abilityHand = drawnCard;
    abilityUsed = false;
    abilityLessVictim = false;
}

void PlayerCandy::useAbility(string abilityName, GameCandy &gC)
{
    if (abilityHand.getName() != abilityName)
    {
        AbilityNotOwned e;
        throw e;
    }

    if (abilityUsed)
    {
        if (abilityLessVictim)
        {
            AbilityNotAvailable e("Oops, kartu abilitymu telah dimatikan sebelumnya :(\nSilahkan lakukan perintah lain.");
            throw e;
        }
        else
        {
            AbilityNotAvailable e("Kamu sudah menggunakan kartu ability-mu sebelumnya");
            throw e;
        }
    }

    abilityHand.activateAbility(gC);
    abilityUsed = true;
}

void PlayerCandy::useAbility(GameCandy &gC)
{
    if (abilityUsed)
    {
        AbilityNotAvailable e;
        throw e;
    }
    abilityHand.activateAbility(gC);
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

int PlayerCandy::compareCombinationWeight(PlayerCandy otherPlayer, DeckGame<ColorCard> deckGame)
{
    Deck<ColorCard> *our = &this->handCards;
    Deck<ColorCard> *their = &otherPlayer.handCards;
    Deck<ColorCard> *table = &deckGame;
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

void PlayerCandy::printCard()
{
    if (abilityHand.getName() != "")
    {
        cout << "|"
             << "\033[1m\033[37m"
             << "  " << getAbilityName() << "\033[0m"
             << "  ";
    }
    Player<ColorCard>::printCard();
}
