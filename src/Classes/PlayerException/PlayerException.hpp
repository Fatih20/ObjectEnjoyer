#include <string>
#include <exception>

using namespace std;

class PlayerException : public exception
{
protected:
    string message;

public:
    PlayerException();
    PlayerException(string message);
    virtual string getMessage();
};

class UsernameEmpty : public PlayerException
{

public:
    UsernameEmpty();
};

class AbilityNotOwned : public PlayerException
{
public:
    AbilityNotOwned();
    string getMessage(string abilityAttempted);
};

class AbilityNotAvailable : public PlayerException
{
public:
    AbilityNotAvailable();
    AbilityNotAvailable(string message);
};