#include <string>
#include <exception>

using namespace std;

class PlayerException : public exception
{
protected:
    string message;

public:
    PlayerException();
    string getMessage();
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
};

class AbilityNotAvailable : public PlayerException
{
public:
    AbilityNotAvailable();
};