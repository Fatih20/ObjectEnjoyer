#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <exception>

using namespace std;

class OptionInvalid : public exception {
    private:
        int option;
    public:
        /**
         * @brief Construct a new Option Invalid object
         * 
         */
        OptionInvalid(int);

        /**
         * @brief Get the Valid option
         * 
         * @return int 
         */
        int getValidOption();
};

#endif
