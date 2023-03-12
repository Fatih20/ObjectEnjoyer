#include <exception>
#include <string>

using namespace std;

class NotEnoughCards : public exception
{
private:
    string message;

public:
    NotEnoughCards() { message = "Not Enough Cards in the Deck of the Game!"; };
    string getMessage() { return message; };
};

class OutOfBoundIndex : public exception
{
private:
    string message;

public:
    OutOfBoundIndex() { this->message = ""; };
    OutOfBoundIndex(string message) { this->message = message; };
    string getMessage() { return message; };
    void setMessage(string message) { this->message = message; };
};