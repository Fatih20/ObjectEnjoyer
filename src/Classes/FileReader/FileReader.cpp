#include "FileReader.hpp"

FileReader::FileReader(string filePath){
    this->filePath = filePath;
}

DeckGame< Card<int> > FileReader::getDeckOrder(){
    return this->deckOrder;
}

DeckGame< Card<int> > FileReader::getAbilityCardOrder(){
    return this->abi;
}


void FileReader::read(){ //beluma ada validasi, execption handling
    string temp;
    int ntc, np, nhc, nac;
    
    fstream f(filePath);
    
    getline(f, temp, ' ');
    ntc = stoi(temp);
    getline(f, temp, ' ');
    np = stoi(temp);
    getline(f, temp, ' ');
    nhc = stoi(temp);
    getline(f, temp, '\n');
    nac = stoi(temp);

    this->handCardCap = np*nhc;
    this->handCardOrder = new string[this->handCardCap];
    for(int i = 0; i < this->handCardCap ; i++){
        if((i + 1) % nhc == 0) getline(f, temp, '\n');
        else getline(f, temp, ' ');
        this->handCardOrder[i] = temp;
    }

    this->abilityCardCap = np*nac;
    this->abilityCardOrder = new string[this->abilityCardCap];
    for(int i = 0; i < this->abilityCardCap ; i++){
        if((i + 1) % nac == 0) getline(f, temp, '\n');
        else getline(f, temp, ' ');
        this->abilityCardOrder[i] = temp;
    }

    this->tableCardCap = ntc;
    this->tableCardOrder = new string[this->tableCardCap];
    for(int i = 0; i < this->tableCardCap; i++){
        getline(f, temp, '\n');
        this->tableCardOrder[i] = temp;
    }

    f.close();
}