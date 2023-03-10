#include <string>
#include <exception>

using namespace std;

class UsernameEmpty : public exception
{
private:
    string message;

public:
    UsernameEmpty();
    string getMessage();
};