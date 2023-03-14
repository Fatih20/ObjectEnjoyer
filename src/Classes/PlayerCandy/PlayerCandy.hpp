#ifndef _PLAYER_CANDY_HPP
#define _PLAYER_CANDY_HPP

#include "../Player/Player.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../AbilityCard/AbilityCard.hpp"
#include "../DeckGame/DeckGame.hpp"

class GameCandy;

class PlayerCandy : public Player<ColorCard>
{
private:
    bool abilityUsed;
    AbilityCard abilityHand;

public:
    /**
     * @brief Construct a new Player Candy object with the given gameID
     *
     * @param gameID
     */
    PlayerCandy(int gameID);

    /**
     * @brief Construct a new Player Candy object with 0 as gameID
     *
     */
    PlayerCandy();

    /**
     * @brief Copy constructor of PlayerCandy
     *
     * @param p
     */
    PlayerCandy(const PlayerCandy &p);

    /**
     * @brief Draw ability card from the deck
     *
     * @param deckAbility
     */
    void drawAbility(DeckGame<AbilityCard> &deckAbility);

    /**
     * @brief Use an ability if the abilityName matches, else throw an error
     *
     * @param abilityName
     * @param gC
     */
    void useAbility(string abilityName, GameCandy &gC);

    void useAbility(GameCandy &gC);
    /**
     * @brief Disable the ability of the player
     *
     */
    void disableAbility();

    /**
     * @brief Return whether the player can still use their ability
     *
     */
    bool getAbilityAvailable();
};

#endif