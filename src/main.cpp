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
    cout << "deckA" << endl;
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, RED);
    Deck<ColorCard> deckA;
    deckA.addCard(cc2);
    deckA.addCard(cc1);
    cout << deckA << endl;
    // p5.printScore();

    cout << "sorted deck" << endl << "deckB" << endl;
    DeckGame<ColorCard> deckB(deckA);
    deckB.sortDeck();
    cout << deckB << endl;

    ColorCard cc3 = deckB.drawCard();

    cout << deckB << endl;
    cout << "drawed card  : " << cc3 << endl;



    return 0;
}