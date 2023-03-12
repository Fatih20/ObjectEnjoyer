#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "Classes/Deck/Deck.hpp"

class Combo{
    public:
        /**
         * @brief Get the Weight of the combo
         *
         * @return int
         */
        virtual int getWeight() = 0;

};

#endif