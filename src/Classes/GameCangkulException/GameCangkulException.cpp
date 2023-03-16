#include "GameCangkulException.hpp"

CangkulCommandInvalid::CangkulCommandInvalid() : CangkulCommandInvalid("no info"){}
CangkulCommandInvalid::CangkulCommandInvalid(string infoMessage) {
    this->infoMessage = infoMessage;
}

const char* CangkulCommandInvalid::what() const throw() {
    string result = this->baseMessage + this->infoMessage;
    return result.data();
}