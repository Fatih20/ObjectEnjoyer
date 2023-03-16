#include "FileReaderException.hpp"


NumberExp::NumberExp(NumberException expType){
    this->expType = expType;
}

const char* NumberExp::what() const throw(){
    switch(this->expType){
        case 0:
            return "Anda memasukan terlalu banyak deck card!\nBanyak masukan kartu yang valid adalah antara 21 sampai 52\n";
        case 1:
            return "Anda memasukan terlalu sedikit deck card!\nBanyak masukan kartu yang valid adalah antara 21 sampai 52\n";
        case 2:
            return "Anda memasukan terlalu banyak ability card!\nBanyak masukan kartu yang valid adalah 7\n";
        case 3:
             return "Anda memasukan terlalu sedikit ability card!\nBanyak masukan kartu yang valid adalah 7\n";
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
            return "Fomat masukan anda untuk deck card salah!\nFormat masukan yang valid adalah \"<warna><spasi><angka>\"\nContoh: \"G 1\"\n";
        case 1:
            return "Format masukan anda untuk warna deck card salah!\nFormat masukan yang valid adalah:\nHijau = G\nBiru = B\nKuning = Y\nMerah = R\n";
        case 2:
            return "Format masukan anda untuk angka deck kard salah!\nFormat masukan ynag valid adalah angka antara 1 sampai 13\n";
        case 3:
            return "Format masukan anda untuk tipe ability card salah!\nFormat masukan yang valid adalah:\nReroll = REROLL\nQuadruple = QUADRUPLE\nQuarter = QUARTER\nReverse = REVERSE\nSwap = SWAP\nSwitch = SWITCH\nAbilityless = ABILITYLESS\n";
        default:
            return " ";
    }
}

const char* FileNotFoundExp::what() const throw(){
    return "File tidak ditemukan! Mohon masukkan path yang benar\n";
}