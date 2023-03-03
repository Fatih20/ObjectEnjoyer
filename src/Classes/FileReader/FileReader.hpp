#ifndef _FILEREADER_HPP_
#define _FILEREADER_HPP_

#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include "Classes/AbilityCard/AbilityCard.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileReader{
    private:
        string filePath;
        DeckGame< Card<int> > deckOrder;
        vector < Card<int> > abilityCardOrder;
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
        DeckGame< Card<int> > getDeckOrder();

        /**
         * @brief Getter for AbilityCardOrder
         * 
         */
        vector< Card<int> > getAbilityCardOrder();

        /**
         * @brief Method to read from file, defining all atributes (except filePath)
         * 
         */
        void read();
};

#endif 

