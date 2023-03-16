#ifndef OBJECTENJOYER_GAMECANGKULEXCEPTION_HPP
#define OBJECTENJOYER_GAMECANGKULEXCEPTION_HPP

#include <string>
#include <exception>

using namespace std;

class CangkulCommandInvalid : public exception {
protected:
    string baseMessage = "Invalid Command : ";
    string infoMessage;

public:
    CangkulCommandInvalid();
    CangkulCommandInvalid(string infoMessage);

    const char* what() const throw();
};

#endif //OBJECTENJOYER_GAMECANGKULEXCEPTION_HPP
