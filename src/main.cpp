#include "Classes/Player/Player.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include "Classes/AbilityCard/AbilityCard.hpp"

#include <vector>

#include <iostream>

int main()
{
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, GREEN);
    Deck<int> deckA;
    deckA.addCard(cc1);
    deckA.addCard(cc2);
    cout << cc1;
    // std::vector<int> valuesA = {2, 3, 4, 5, 6};
    // std::vector<int> valuesB = {-12, -13, -134, -9, -23};

    // Deck<int> deckA(valuesA);
    // Deck<int> deckB(valuesB);

    // std::cout <<    "[first]" << std::endl <<
    //                 "deck A" << deckA << std::endl <<
    //                 "deck B" << deckB << std::endl;

    // Deck<int>::swapDeck(deckA, deckB);

    // std::cout <<    "[swapping]" << std::endl <<
    //                 "deck A" << deckA << std::endl <<
    //                 "deck B" << deckB << std::endl;

    // deckA.swap(deckB);

    // std::cout <<    "[swapping]" << std::endl <<
    //                 "deck A" << deckA << std::endl <<
    //                 "deck B" << deckB << std::endl;

    // p5.printScore();

    return 0;
}