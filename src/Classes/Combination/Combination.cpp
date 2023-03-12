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
    score = -1;
    calculate(player, table);
}

void Combination::calculate(vector<ColorCard> player, vector<ColorCard> table){
    do{
        isStraightFlush();
        isFourOfAKind();
        isFullHouse();
        isFlush();
        isStraight();
        isThreeOfAKind();
        isTwoPair();
        isOnePair();
    }while(prev_permutation(allCards.begin(), allCards.end()));
    getHighestCard();
}

void Combination::getHighestCard(){
    if(combinationType == HIGH_CARD){
        sort(playerCards.begin(), playerCards.end(), [](ColorCard a, ColorCard b){
            return a.value() > b.value();
        });
        score = playerCards[0].value();
    }

    for(int i = 0 ; i < usedCards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), usedCards[i]) != playerCards.end()){
            score = usedCards[i].value();
            return;
        }
    }
}

void Combination::isOnePair(){
    if(allCards[0].getNumber() == allCards[1].getNumber()){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        if(inPlayer()){
            if(combinationType < PAIR){
                combinationType = PAIR;
            }
        }
    }
}

void Combination::isTwoPair(){
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[2].getNumber() == allCards[3].getNumber()){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        if(inPlayer()){
            if(combinationType < TWO_PAIRS){
                combinationType = TWO_PAIRS;
            }
        }
    }
}

void Combination::isThreeOfAKind(){
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber()){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        if(inPlayer()){
            if(combinationType < THREE_OF_A_KIND){
                combinationType = THREE_OF_A_KIND;
            }
        }
    }
}

void Combination::isFourOfAKind(){
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber() && allCards[2].getNumber() == allCards[3].getNumber()){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        if(inPlayer()){
            if(combinationType < FOUR_OF_A_KIND){
                combinationType = FOUR_OF_A_KIND;
            }
        }
    }
}

void Combination::isStraight(){
    bool isStraight = true;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getNumber() != allCards[i+1].getNumber() + 1){
            isStraight = false;
            break;
        }
    }
    if(isStraight){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        usedCards.push_back(allCards[4]);
        if(inPlayer()){
            if(combinationType < STRAIGHT){
                combinationType = STRAIGHT;
            }
        }
    }
}

void Combination::isFlush(){
    bool isFlush = true;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getColor() != allCards[i+1].getColor()){
            isFlush = false;
            break;
        }
    }
    if(isFlush){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        usedCards.push_back(allCards[4]);
        if(inPlayer()){
            if(combinationType < FLUSH){
                combinationType = FLUSH;
            }
        }
    }
}

void Combination::isFullHouse(){
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber() && allCards[3].getNumber() == allCards[4].getNumber()){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        usedCards.push_back(allCards[4]);
        if(inPlayer()){
            if(combinationType < FULL_HOUSE){
                combinationType = FULL_HOUSE;
            }
        }
    }
}

void Combination::isStraightFlush(){
    bool isStraightFlush = true;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getNumber() != allCards[i+1].getNumber() + 1 || allCards[i].getColor() != allCards[i+1].getColor()){
            isStraightFlush = false;
            break;
        }
    }
    if(isStraightFlush){
        usedCards.push_back(allCards[0]);
        usedCards.push_back(allCards[1]);
        usedCards.push_back(allCards[2]);
        usedCards.push_back(allCards[3]);
        usedCards.push_back(allCards[4]);
        if(inPlayer()){
            if(combinationType < STRAIGHT_FLUSH){
                combinationType = STRAIGHT_FLUSH;
            }
        }
    }
}

bool Combination::inPlayer(){
    for(int i = 0; i < usedCards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), usedCards[i]) != playerCards.end()){
            return true;
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

bool Combination::operator<(Combination& other){
    if(this->combinationType < other.combinationType){
        return true;
    }
    else if(this->combinationType == other.combinationType){
        if(this->score < other.score){
            return true;
        }
    }
    return false;
}

bool Combination::operator>(Combination& other){
    if(this->combinationType > other.combinationType){
                return true;
    }
    else if(this->combinationType == other.combinationType){
        if(this->score > other.score){
            return true;
        }
    }
    return false;
}