#include "Deck/Deck.hpp"
#include "DeckGame/DeckGame.hpp"

#include <vector>

#include <iostream>

int main(){
    std::vector<int> keo;

    keo.push_back(10);
    keo.push_back(11);

    Deck<int> deck(keo);

    keo.push_back(12);

    Deck<int> dack(keo);


    std::cout << deck;
    std::cout << dack;

    deck.swap(dack);

    std::cout << deck;
    std::cout << dack;

    DeckGame<int> dega(keo);

    std::cout <<  std::endl << "drawed card " << dega.drawCard() << std::endl << dega;

    return 0;
}