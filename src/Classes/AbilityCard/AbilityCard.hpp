#ifndef _ABILITYCARD_HPP_
#define _ABILITYCARD_HPP_

#include "Classes/Card/Card.hpp"
#include <string>

typedef enum{
    REROLL, // Reroll all hand cards
    QUADRUPLE, // Quadruple the reward of the current round
    QUARTER, // Quarter the reward of the current round
    REVERSE, // Reverse the order of the players
    SWAP, // Swap a card from the hand with a card from another player's hand
    SWITCH, // Switch the hand cards with another player's hand cards
    ABILITYLESS // Disable the ability of a specific player
} Ability;

// bagaimana memasukkan enumeration ke dalam template?

class AbilityCard: public Card<int> {
    private:
        std::string description;
    
    public:
        /**
         * @brief Construct a new Ability Card object with given ability
         * 
         * @param value The ability of the card (REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS)
         */
        AbilityCard(int value, std::string description);
        // CCtor dan assignment operator tidak perlu karena tidak ada pointer
        // Dtor tidak perlu karena hanya menyimpan data sederhana

        /**
         * @brief Get the Ability of the card from integer conversion to enum
         * 
         */
        Ability getAbility();

        /**
         * @brief Get the description of the card (for example, REROLL: reroll all hand cards)
         */
        std::string getDescription();

        // Aktivasi kartu perlu terhubung ke kelas Game untuk mengubah kondisi game
        // Tidak dibuat setter karena nilai kartu tidak perlu diubah
};

#endif