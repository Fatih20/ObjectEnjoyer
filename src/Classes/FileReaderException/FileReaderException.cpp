#include "FileReaderException.hpp"


NumberExp::NumberExp(NumberException expType){
    this->expType = expType;
}

const char* NumberExp::what() const throw(){
    switch(this->expType){
        case 0:
            return "You've inputted to many deck card!\nValid input should be between 21 - 52\n";
        case 1:
            return "You've inputted not enough deck card!\nValid input should be between 21 - 52\n";
        case 2:
            return "You've inputted to many ability card!\nValid input is 7\n";
        case 3:
             return "You've inputted not enough ability card!\nValid input is 7\n";
        default:
            return " ";
    }
}

FormatExp::FormatExp(FormatException expType){
    this->expType = expType;
}

const char* FormatExp::what() const throw(){
    switch(this->expType){
        case 0:
            return "Deck Card input format wrong!\nValid format is: \"<warna><spasi><angka>\"\nContoh: \"G 1\"\n";
        case 1:
            return "Deck Card color format wrong!\nValid format is:\nGreen = G\nBlue= B\nYellow = Y\nRed= R\n";
        case 2:
            return "Deck Card value format wrong!\nValid format is between 1 - 13\n";
        case 3:
            return "Ability card type format wrong!\nValid format is:\nReroll = REROLL\nQuadruple = QUADRUPLE\nQuarter = QUARTER\nReverse = REVERSE\nSwap = SWAP\nSwitch = SWITCH\nAbilityless = ABILITYLESS\n";
        default:
            return " ";
    }
}

const char* FileNotFoundExp::what() const throw(){
    return "File not found! Please input correct path.\n";
}