#ifndef _DECKTABLE_HPP_
#define _DECKTABLE_HPP_


#include "Classes/Deck/Deck.hpp"

#include <vector>

template <class T>
class DeckTable : public Deck {
    public:
        DeckTable();

        DeckTable(std::vector<T> vec);

        DeckTable(const DeckTable& other);

        ~DeckTable();
};

#endif