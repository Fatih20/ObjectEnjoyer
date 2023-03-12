#include "GameCandyException.hpp"

CommandInvalid::CommandInvalid(string invalidCommand){
    this->invalidCommand = invalidCommand;
}

string CommandInvalid::getInvalidCommand(){
    return this->invalidCommand;
}
