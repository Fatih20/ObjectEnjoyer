#ifndef _FILEREADER_HPP_
#define _FILEREADER_HPP_

#include "../DeckGame/DeckGame.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../AbilityCard/AbilityCard.hpp"
#include "../Abilities/Abilities.hpp"
#include "../Ability/Ability.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <class T1, class T2>
class FileReader{
    private:
        string filePath;
        DeckGame<T1> deckOrder;
        DeckGame<T2> abilityCardOrder;
    public:
        /**
         * @brief User-defined constructor, defining filePath
         * 
         * @param filePath file's path
         */
        FileReader(string filePath);

        /**
         * @brief Getter for DeckOrder
         * 
         */
        DeckGame<T1> getDeckOrder();

        /**
         * @brief Getter for AbilityCardOrder
         * 
         */
        DeckGame<T2> getAbilityCardOrder();

        /**
         * @brief Method to read from file, defining all atributes (except filePath)
         * 
         */
        void read();
};

/*
FILE FORMAT

  <color><space><value>
  <color><space><value>
  ...
  -
  <ability-type>

  color format: G = green, B = blue, R = red, Y = yellow
  value format: 1 - 13
  ability-type format: REROLL, QUADRUPLE, QUARTER, REVERSE, SWAP, SWITCH, ABILITYLESS.
  color card input must be between 21 - 52 cards
  ability card input must be exactly 7
*/
#endif 
