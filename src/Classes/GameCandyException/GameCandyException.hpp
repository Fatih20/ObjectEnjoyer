#ifndef GAMECANDYEXCEPTION_HPP
#define GAMECANDYEXCEPTION_HPP

#include <string>
#include <exception>

using namespace std;

class CommandInvalid : public exception{
    private:
        string invalidCommand;

    public:
        /**
         * @brief Construct a new Command Invalid object
         * 
         */
        CommandInvalid(string);

        /**
         * @brief Return the problematic username
         *
         * @return string username
         */
        string getInvalidCommand();


};

#endif
