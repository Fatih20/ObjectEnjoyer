#include <string>
#include <exception>
#include <iostream>

using namespace std;

typedef enum{
    DECK_TOO_MUCH,
    DECK_NOT_ENOUGH,
    ABILITY_TOO_MUCH,
    ABILITY_NOT_ENOUGH
} NumberException;

typedef enum{
    DELIM,
    TYPE_COLOR_DECK,
    TYPE_VALUE_DECK,
    TYPE_ABILITY
} FormatException;


class NumberExp: public exception{
    public:
        NumberExp(NumberException);
        const string msg();
    private:
        NumberException expType;
};

class FormatExp: public exception{
    public:
        FormatExp(FormatException);
        const string msg();
    private:
        FormatException expType;
};