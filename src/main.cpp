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
    cout << "[deckA]" << endl;
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, RED);
    ColorCard cc3(3, BLUE);
    ColorCard cc4(4, YELLOW);
    Deck<ColorCard> deckA;
    deckA.addCard(cc1);
    deckA += cc2;
    deckA << cc3;
    deckA.addCard(cc4);
    cout << deckA << endl;
    // p5.printScore();


    cout << "[deckB]" << endl;
    cout << "shuffled" << endl;
    DeckGame<ColorCard> deckB(deckA);
    deckB.shuffle();
    cout << deckB << endl;

    cout << "sorted" << endl;
    deckB.sort();
    cout << deckB << endl;

    ColorCard ccdraw = deckB.drawCard();

    cout << deckB << endl;
    cout << "drawed card  : " << ccdraw << endl;



    return 0;
}