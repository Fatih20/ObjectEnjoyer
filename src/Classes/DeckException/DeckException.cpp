#include "DeckException.hpp"

const char* EmptyDeckException::what() const throw() {
    return "DeckException : Deck is empty!";
}