#include "Combination.hpp"
#include <algorithm>
#include <iostream>

Combination::Combination(vector<ColorCard> player, vector<ColorCard> table){
    playerCards = player;
    allCards = player;
    allCards.insert(allCards.end(), table.begin(), table.end());
    sort(allCards.begin(), allCards.end(), [](ColorCard a, ColorCard b){
        return a.value() > b.value();
    });
    // calculate(player, table);
}

// void Combination::calculate(vector<ColorCard> player, vector<ColorCard> table){
//     if(isStraightFlush(player, table)){
//         combinationType = STRAIGHT_FLUSH;
//     }
//     else if(isFourOfAKind(player, table)){
//         combinationType = FOUR_OF_A_KIND;
//     }
//     else if(isFullHouse(player, table)){
//         combinationType = FULL_HOUSE;
//     }
//     else if(isFlush(player, table)){
//         combinationType = FLUSH;
//     }
//     else if(isStraight(player, table)){
//         combinationType = STRAIGHT;
//     }
//     else if(isThreeOfAKind(player, table)){
//         combinationType = THREE_OF_A_KIND;
//     }
//     else if(isTwoPair(player, table)){
//         combinationType = TWO_PAIRS;
//     }
//     else if(isOnePair(player, table)){
//         combinationType = PAIR;
//     }
//     else{
//         combinationType = HIGH_CARD;
//         getHighestCard(player, table);
//     }
// }

bool Combination::inPlayer(){
    for(int i = 0; i < usedCards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), usedCards[i]) != playerCards.end()){
            return true;
        }
    }
    return false;
}

bool Combination::isOnePair(vector<ColorCard> player, vector<ColorCard> table){
    this->usedCards.clear();
    for(int i = 0; i < allCards.size(); i++){
        for(int j = i + 1; j < allCards.size(); j++){
            if(allCards[i].getNumber() == allCards[j].getNumber()){
                this->usedCards.push_back(allCards[i]);
                this->usedCards.push_back(allCards[j]);
                if(inPlayer()){
                    return true;
                } else {
                    usedCards.clear();
                }
            }
        }
    }
    return false;
}



// buat dengan array of cards dulu, baru diubah ke deck nanti ketika dack udah jadi

/*
boleh selama:
1. ga overlap
2. ngehandle kasus2 ujung, kayak kalau ditable semuanya straight flush, harus lihat dari kartu selain itu
3. handle kasus kalau semua maksimal pair 5, tapi 5 merah ada di meja, harus lihat dari pair 5 warna kartu kedua
4. ga ngilangin konsep oop
5. ada subtitusi penggunaan oop, jangan sampe gegara implementasi sendiri, misal polymorphismnya ilang, ini gada toleransi
*/

void Combination::print(){
    switch(combinationType){
        case HIGH_CARD:
            cout << "High Card" << endl;
            break;
        case PAIR:
            cout << "Pair" << endl;
            break;
        case TWO_PAIRS:
            cout << "Two Pairs" << endl;
            break;
        case THREE_OF_A_KIND:
            cout << "Three of a Kind" << endl;
            break;
        case STRAIGHT:
            cout << "Straight" << endl;
            break;
        case FLUSH:
            cout << "Flush" << endl;
            break;
        case FULL_HOUSE:
            cout << "Full House" << endl;
            break;
        case FOUR_OF_A_KIND:
            cout << "Four of a Kind" << endl;
            break;
        case STRAIGHT_FLUSH:
            cout << "Straight Flush" << endl;
            break;
    }
    for(int i = 0; i < usedCards.size(); i++){
        usedCards[i].print();
    }
    cout<<"Score: "<<score<<endl;
    cout<<"All Cards: "<<endl;
    for(int i = 0; i < allCards.size(); i++){
        allCards[i].print();
    }
}