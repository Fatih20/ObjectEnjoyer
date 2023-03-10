#include <string>
#include <exception>

using namespace std;

class UsernameExist : public exception
{
private:
    string notUniqueUsername;

public:
    /**
     * @brief Construct a new Username Exist object with the given username as the username that is not unique
     *
     */
    UsernameExist(string);

    /**
     * @brief Return the problematic username
     *
     * @return string username
     */
    string getUsernameThatExist();
};

class UsernameEmpty : public exception
{
public:
    UsernameEmpty();
};