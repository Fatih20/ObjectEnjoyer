#include "FileReader.hpp"
#include "../Classes/FileReaderException/FileReaderException.hpp"

template <typename T1, typename T2>
FileReader<T1, T2>::FileReader(string filePath){
    this->filePath = filePath;
}

template <typename T1, typename T2>
DeckGame<T1> FileReader<T1, T2>::getDeckOrder(){
    return this->deckOrder;
}

template <typename T1, typename T2>
DeckGame<T2> FileReader<T1, T2>::getAbilityCardOrder(){
    return this->abilityCardOrder;
}

template <typename T1, typename T2>
void FileReader<T1, T2>::read(){ 
    string temp, token[2];   
    ifstream f;
    vector<ColorCard> deckVec;
    Color color;
    vector<AbilityCard> abiVec;
    bool stop = false;
    f.open(this->filePath);
    if(!f) throw FileNotFoundExp();
    int pos = 0, i, value;
    while(!stop && getline(f, temp)) {
        if(temp == "-") stop = true;
        else{
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
    }
    if(deckVec.size() > 52) throw NumberExp(DECK_TOO_MUCH);
    else if(deckVec.size() < 21) throw NumberExp(DECK_NOT_ENOUGH);
    deckOrder.setDeck(deckVec);
    while(getline(f, temp)){
        if(temp == "REROLL") {
            shared_ptr<Reroll> abi = make_shared<Reroll>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "QUADRUPLE"){
            shared_ptr<Quadruple> abi = make_shared<Quadruple>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "QUARTER"){
            shared_ptr<Quarter> abi = make_shared<Quarter>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "REROLL"){
            shared_ptr<Reroll> abi = make_shared<Reroll>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "REVERSE"){
            shared_ptr<Reverse> abi = make_shared<Reverse>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "SWAP"){
            shared_ptr<Swap> abi = make_shared<Swap>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "SWITCH"){
            shared_ptr<Switch> abi = make_shared<Switch>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else if(temp == "ABILITYLESS"){
            shared_ptr<Abilityless> abi = make_shared<Abilityless>();
            AbilityCard abilityCard(abi);
            abiVec.insert(abiVec.begin(), abilityCard);
        }
        else throw FormatExp(TYPE_ABILITY);
    }
    if(abiVec.size() > 7) throw NumberExp(ABILITY_TOO_MUCH);
    else if(abiVec.size() < 7) throw NumberExp(ABILITY_NOT_ENOUGH);
    abilityCardOrder.setDeck(abiVec);
    f.close();
}

template class FileReader<ColorCard, AbilityCard>;