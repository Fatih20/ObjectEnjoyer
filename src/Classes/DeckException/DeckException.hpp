#ifndef _DECKEXCEPTION_HPP
#define _DECKEXCEPTION_HPP

#include <exception>

class DeckException : public std::exception {
    public:
        virtual const char* what() const throw() = 0;
};

class EmptyDeckException : public DeckException {
    public:
        const char* what() const throw();
};

#endif
