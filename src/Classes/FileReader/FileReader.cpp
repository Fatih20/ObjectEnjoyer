#include "FileReader.hpp"

FileReader::FileReader(string filePath){
    this->filePath = filePath;
}

FileReader::~FileReader(){
    delete[] this->handCardOrder;
    delete[] this->abilityCardOrder;
    delete[] this->tableCardOrder;
}

int FileReader::getHandCardCap(){
    return this->handCardCap;
}

int FileReader::getAbilityCardCap(){
    return this->abilityCardCap;
}

int FileReader::getTableCardCap(){
    return this->tableCardCap;
}

string* FileReader::getHandCardOrder(){
    return this->handCardOrder;
}

string* FileReader::getAbilityCardOrder(){
    return this->abilityCardOrder;
}

string* FileReader::getTableCardOrder(){
    return this->tableCardOrder;
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