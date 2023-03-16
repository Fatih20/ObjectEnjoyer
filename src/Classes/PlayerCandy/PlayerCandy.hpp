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
     * @brief Construct a new Player Candy object with the given gameID and drawing a card from the deck game
     *
     * @param gameID
     * @param deckGame
     *
     */
    PlayerCandy(int gameID, DeckGame<AbilityCard> &deckGame);

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

    /**
     * @brief Get the Ability Name object
     *
     * @return string
     */
    string getAbilityName();

    /**
     * @brief Return 1 if this player is higher, 0 if same, -1 if this player is lower
     *
     * @param otherPlayer
     * @param deckGame
     * @return int
     */
    int compareCombinationWeight(PlayerCandy otherPlayer, DeckGame<ColorCard> deckGame);

    /**
     * @brief Return true if we have equal combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return int
     */
    bool equalCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame);

    /**
     * @brief Return true if this player have lower combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return true
     * @return false
     */
    bool lowerCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame);

    /**
     * @brief Return true if this player have bigger combination weight
     *
     * @param otherPlayer
     * @param deckGame
     * @return true
     * @return false
     */
    bool higherCombinationWeight(const PlayerCandy &otherPlayer, const DeckGame<ColorCard> &deckGame);

    void test();
};

#endif