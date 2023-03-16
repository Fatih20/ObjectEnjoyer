#include "Combination.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "../DeckPlayer/DeckPlayer.hpp"

int main(){
    DeckGame<ColorCard> table;
    table+=ColorCard(2,RED);
    table+=ColorCard(8,GREEN);
    table+=ColorCard(11,RED);

    DeckPlayer<ColorCard> player1;
    player1+=ColorCard(6, BLUE);
    player1+=ColorCard(4, YELLOW);

    DeckPlayer<ColorCard> player2;
    player2+=ColorCard(12, GREEN);
    player2+=ColorCard(11, YELLOW);

    DeckPlayer<ColorCard> player3;
    player3+=ColorCard(13, BLUE);
    player3+=ColorCard(10, BLUE);

    DeckPlayer<ColorCard> player4;
    player4+=ColorCard(12, RED);
    player4+=ColorCard(7, RED);

    DeckPlayer<ColorCard> player5;
    player5+=ColorCard(1, YELLOW);
    player5+=ColorCard(3, YELLOW);

    DeckPlayer<ColorCard> player6;
    player6+=ColorCard(9, GREEN);
    player6+=ColorCard(7, GREEN);

    DeckPlayer<ColorCard> player7;
    player7+=ColorCard(9, RED);
    player7+=ColorCard(10, RED);

    Deck<ColorCard> *d1 = &player1;
    Deck<ColorCard> *d2 = &table;
    Combination p1(*d1, *d2);
    d1 = &player2;
    Combination p2(*d1, *d2);
    d1 = &player3;
    Combination p3(*d1, *d2);
    d1 = &player4;
    Combination p4(*d1, *d2);
    d1 = &player5;
    Combination p5(*d1, *d2);
    d1 = &player6;
    Combination p6(*d1, *d2);
    d1 = &player7;
    Combination p7(*d1, *d2);

    Combination arr[7] = {p1, p2, p3, p4, p5, p6, p7};
    Deck<ColorCard> dummy;
    dummy.addCard(ColorCard(0, GREEN));
    Combination highest(dummy);
    int index = 0;

    std::cout << "oke\n";

    for(int i = 0 ; i < 7 ; i++){
        std::cout << "=========================\n";
        std::cout << "Player " << i+1 << ":\n";
        arr[i].print();
        std::cout << "=========================\n";
        if(arr[i] > highest){
            highest = arr[i];
            index = i+1;
        }
    }
    std::cout << "HIGHEST: " << index << "\n";
    highest.print();
    return 0;
}