#ifndef _COMBOMAIN_HPP_
#define _COMBOMAIN_HPP_

#include "Classes/Combo/Combo.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"

class ComboMain : public Combo {

    // note : gw masih bingung combo ini class nya mau dibuat ke mana
    public:
        template <typename T>
        static int getCombinationWeight(const DeckGame<T>& a, const DeckPlayer<T>& b);

};

#endif

