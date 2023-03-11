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