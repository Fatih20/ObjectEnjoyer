#include "Classes/Player/Player.hpp"

int main()
{

    Player p5;
    p5 += 10;
#include "Deck/Deck.hpp"
#include "DeckGame/DeckGame.hpp"

#include <vector>

#include <iostream>

int main(){
    std::vector<int> valuesA = {2, 3, 4, 5, 6};
    std::vector<int> valuesB = {-12, -13, -134, -9, -23};

    Deck<int> deckA(valuesA);
    Deck<int> deckB(valuesB);

    std::cout <<    "[first]" << std::endl << 
                    "deck A" << deckA << std::endl << 
                    "deck B" << deckB << std::endl;

    Deck<int>::swapDeck(deckA, deckB);

    std::cout <<    "[swapping]" << std::endl << 
                    "deck A" << deckA << std::endl << 
                    "deck B" << deckB << std::endl;

    deckA.swap(deckB);

    std::cout <<    "[swapping]" << std::endl << 
                    "deck A" << deckA << std::endl << 
                    "deck B" << deckB << std::endl;




    p5.printScore();
}
    return 0;
}