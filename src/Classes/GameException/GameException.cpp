#include "GameException.hpp"

OptionInvalid::OptionInvalid(int optionRange){
    this->option = optionRange;
}

int OptionInvalid::getValidOption(){
    return this->option;
}
