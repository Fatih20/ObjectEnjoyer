#include <string>
#include <exception>

using namespace std;

class PlayerException : public exception
{
private:
    string message;

public:
    PlayerException();
    string getMessage();
};

class UsernameEmpty : public PlayerException
{
private:
    string message;

public:
    UsernameEmpty();
};

class AbilityNotOwned : public PlayerException
{
private:
    string message;

public:
    AbilityNotOwned();
};