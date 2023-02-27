#ifndef _FILEREADER_HPP_
#define _FILEREADER_HPP_

#include <iostream>
#include <fstream>

using namespace std;

class FileReader{
    private:
        string filePath;
        string* handCardOrder; // ini nanti kyknya mending array of card (?)
        string* abilityCardOrder;
        string* tableCardOrder;
        int handCardCap;
        int abilityCardCap;
        int tableCardCap;
    public:
        /**
         * @brief User-defined constructor, defining filePath
         * 
         * @param filePath file's path
         */
        FileReader(string filePath);

        /**
         * @brief Destructor
         * 
         */
        ~FileReader();

        /**
         * @brief Getter for handCardOrder capacity
         * 
         */
        int getHandCardCap();

        /**
         * @brief Getter for abilityCardOrder capacity
         * 
         */
        int getAbilityCardCap();

        /**
         * @brief Getter for tableCardOrder capacity
         * 
         */
        int getTableCardCap();

        /**
         * @brief Getter for handCardOrder array
         * 
         */
        string* getHandCardOrder();

        /**
         * @brief Getter for abilityCardOrder array
         * 
         */
        string* getAbilityCardOrder();

        /**
         * @brief Getter for tableCardOrder array
         * 
         */
        string* getTableCardOrder();

        /**
         * @brief Method to read from file, defining all atributes (except filePath)
         * 
         */
        void read();
};

#endif 

/* Input File.txt format */
/* 
X X X X > numoftablecard numofplayer numofhandcard numofabilitycard
A B -- (player 1) > player hand card
A B        .      
A B        .
A B        .
A B        .
A B        .
A B -- (player 7)
C -- (player 1) > player ability card
C       .      
C       .
C       .
C       .
C       .
C -- (player 7)
A -- (round 1) > table card
B       .
A       .
B       .
A -- (round 5)
*/
