#include <string>
#include <exception>

using namespace std;

class UsernameEmpty : public exception
{
public:
    UsernameEmpty();
};