#include "Classes/Player/Player.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
// #include "Classes/AbilityCard/AbilityCard.hpp"
#include "Classes/GameCandy/GameCandy.hpp"
#include "Classes/Combination/Combination.hpp"
#include "Classes/SplashScreen/SplashScreen.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // cout << "[deckA]" << endl;
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, RED);
    ColorCard cc3(3, BLUE);
    ColorCard cc4(4, YELLOW);
    ColorCard cc5(4, YELLOW);
    ColorCard cc6(4, YELLOW);
    ColorCard cc7(4, YELLOW);
    ColorCard cc8(4, YELLOW);
    ColorCard cc9(4, YELLOW);

    vector<ColorCard> vec;
    vec.push_back(cc1);
    vec.push_back(cc2);

    Deck<ColorCard> deckA(vec);
    deckA.addCard(cc1);
    deckA.addCard(cc2);
    deckA.addCard(cc3);
    deckA.addCard(cc4);
    deckA.addCard(cc5);
    deckA.addCard(cc6);
    deckA.addCard(cc7);
    deckA.addCard(cc8);
    deckA.addCard(cc9);

    // deckA.sort(true);
    // cout << deckA << endl;
    // // p5.printScore();

    // cout << "[deckB]" << endl;
    // cout << "shuffled" << endl;
    // DeckGame<ColorCard> deckB(deckA);
    // deckB.shuffle();
    // cout << deckB << endl;

    // // cout << "sorted" << endl;

    // deckB.sort();
    // cout << deckB << endl;

    // ColorCard ccdraw = deckB.ejectCard();

    // cout << "deck B" << endl;
    // cout << deckB << endl;
    // cout << "ejected card  : " << ccdraw << endl;

    // ColorCard ccdraw_dupe = ccdraw;
    // cout << "ejected card : ";
    // ccdraw_dupe.print();
    // cout << endl;

    // Deck<ColorCard> deckC;
    // deckB >> deckC;
    // cout << "deckB" << deckB << endl
    //      << "deckC" << deckC;

    // // card
    // cout << "CARD Combination section" << endl;
    // // input example : input these into terminal :
    // //            9 1
    // //            10 3
    // //            5 1
    // //            6 1
    // //            7 2
    // //            8 1
    // //            13 1

    // vector<ColorCard> player;
    // vector<ColorCard> table;
    // for (int i = 0; i < 2; i++)
    // {
    //     int value;
    //     int color;
    //     cin >> value >> color;
    //     player.push_back(ColorCard(value, Color(color)));
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     int value;
    //     int color;
    //     cin >> value >> color;
    //     table.push_back(ColorCard(value, Color(color)));
    // }
    // Combination comb(player, table);
    // comb.print();

    // Deck<ColorCard> deckD = deckB + deckC;
    // // ColorCard ccdraw = deckB.drawCard();

    // // cout << deckB << endl;
    // // cout << "drawed card  : " << ccdraw << endl;

    // cout << deckD << deckB << deckC << endl;
    SplashScreen::splashScreenMain();
    GameCandy game;
    game.start();
    return 0;
}