#include "FileReader.hpp"
#include "../Classes/FileReaderException/FileReaderException.hpp"

template <typename T>
FileReader<T>::FileReader(string filePath){
    this->filePath = filePath;
}

template <typename T>
DeckGame<T> FileReader<T>::getDeckOrder(){
    return this->deckOrder;
}

// template <typename T>
// vector<T> FileReader<T>::getAbilityCardOrder(){
//     return this->abilityCardOrder;
// }

template <typename T>
void FileReader<T>::read(){ 
    string temp, token[2];   
    ifstream f;
    vector<ColorCard> deckVec;
    Color color;
    //Ability ability;
    f.open(this->filePath);
    if(!f) throw FileNotFoundExp();
    int pos = 0, i, value;
    while(getline(f, temp) && temp != "\n") {
        i = 0;
        while ((pos = temp.find(' ')) != string::npos){
            token[i] = temp.substr(0, pos);
            i++;
            temp.erase(0, pos + 1);
        }
        token[i] = temp.substr(0, 1);
        if(i != 1) throw FormatExp(DELIM);
        if(token[0] == "G") color = GREEN;
        else if(token[0] == "B") color = BLUE;
        else if(token[0] == "Y") color = YELLOW;
        else if(token[0] == "R") color = RED;
        else throw FormatExp(TYPE_COLOR_DECK);

        if(token[1] == "1") value = 1;
        else if(token[1] == "2") value = 2;
        else if(token[1] == "3") value = 3;
        else if(token[1] == "4") value = 4;
        else if(token[1] == "5") value = 5;
        else if(token[1] == "6") value = 6;
        else if(token[1] == "7") value = 7;
        else if(token[1] == "8") value = 8;
        else if(token[1] == "9") value = 9;
        else if(token[1] == "10") value = 10;
        else if(token[1] == "11") value = 11;
        else if(token[1] == "12") value = 12;
        else if(token[1] == "13") value = 13;
        else throw FormatExp(TYPE_VALUE_DECK);

        ColorCard colorCard(value, color);
        deckVec.push_back(colorCard);
    }
    if(deckVec.size() > 52) throw NumberExp(DECK_TOO_MUCH);
    else if(deckVec.size() < 21) throw NumberExp(DECK_NOT_ENOUGH);
    deckOrder.setDeck(deckVec);

    // while(getline(f, temp, '\n')) {
    //     if(temp == "REROLL") ability = REROLL;
    //     else if(temp == "QUADRUPLE") ability = QUADRUPLE;
    //     else if(temp == "QUARTER") ability = QUARTER;
    //     else if(temp == "REVERSE") ability = REVERSE;
    //     else if(temp == "SWAP") ability = SWAP;
    //     else if(temp == "SWITCH") ability = SWITCH;
    //     else if(temp == "ABILITYLESS") ability = ABILITYLESS;
    //     else throw FormatExp(TYPE_ABILITY);
    //     AbilityCard abilityCard(ability, " ");
    //     this->abilityCardOrder.push_back(abilityCard);
    // }
    // if(abilityCardOrder.size() > 7) throw NumberExp(ABILITY_TOO_MUCH);
    // else if(abilityCardOrder.size() < 7) throw NumberExp(ABILITY_NOT_ENOUGH);
    f.close();
}

template class FileReader<ColorCard>;