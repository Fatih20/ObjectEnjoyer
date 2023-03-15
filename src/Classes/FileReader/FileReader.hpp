#ifndef _FILEREADER_HPP_
#define _FILEREADER_HPP_

#include "../Classes/DeckGame/DeckGame.hpp"
#include "../Classes/ColorCard/ColorCard.hpp"
#include "../Classes/AbilityCard/AbilityCard.hpp"
#include "../Classes/Abilities/Abilities.hpp"
#include "../Classes/Ability/Ability.hpp"
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

#endif 
