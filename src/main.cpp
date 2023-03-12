#include "Classes/Combination/Combination.hpp"
#include <iostream>
using namespace std;

int main(){
    vector<ColorCard> player;
    vector<ColorCard> table;
    for(int i = 0; i < 2; i++){
        int value;
        int color;
        cin >> value >> color;
        player.push_back(ColorCard(value, Color(color)));
    }
    for(int i = 0; i < 5; i++){
        int value;
        int color;
        cin >> value >> color;
        table.push_back(ColorCard(value, Color(color)));
    }
    Combination comb(player, table);
    comb.print();
}