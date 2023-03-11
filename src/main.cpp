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
    ColorCard cc2(2, RED);
    Deck<ColorCard> deckA;
    deckA.addCard(cc1);
    deckA.addCard(cc2);
    cout << deckA << endl;
    // p5.printScore();

    DeckGame<ColorCard> deckB(deckA);

    cout << deckB << endl;



    return 0;
}