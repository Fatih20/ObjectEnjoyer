#include "Combination.hpp"
#include <algorithm>
#include <iostream>

Combination::Combination(vector<ColorCard> player, vector<ColorCard> table){
    combinationType = HIGH_CARD;
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
    if(combinationType == HIGH_CARD){
        usedCards = playerCards;
        getHighestCard();
    }
}

void Combination::getHighestCard(){
    for(int i = 0; i < usedCards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), usedCards[i]) != playerCards.end()){
            if(score <= usedCards[i].value()){
                score = usedCards[i].value();
            }
        }
    }
}

void Combination::isOnePair(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        if(inPlayer(temp)){
            if(combinationType <= PAIR){
                combinationType = PAIR;
                usedCards = temp;
                getHighestCard();
            }
        }
    }
}

void Combination::isTwoPair(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[2].getNumber() == allCards[3].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        if(inPlayer(temp)){
            if(combinationType < TWO_PAIRS){
                usedCards = temp;
                combinationType = TWO_PAIRS;
                getHighestCard();
            }
        }
    }
}

void Combination::isThreeOfAKind(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        if(inPlayer(temp)){
            if(combinationType <= THREE_OF_A_KIND){
                usedCards = temp;
                combinationType = THREE_OF_A_KIND;
                getHighestCard();
            }
        }
    }
}

void Combination::isFourOfAKind(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber() && allCards[2].getNumber() == allCards[3].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        if(inPlayer(temp)){
            if(combinationType <= FOUR_OF_A_KIND){
                usedCards = temp;
                combinationType = FOUR_OF_A_KIND;
                getHighestCard();
            }
        }
    }
}

void Combination::isStraight(){
    bool isStraight = true;
    vector<ColorCard> temp;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getNumber() != allCards[i+1].getNumber() + 1){
            isStraight = false;
            break;
        }
    }
    if(isStraight){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        temp.push_back(allCards[4]);
        if(inPlayer(temp)){
            if(combinationType <= STRAIGHT){
                usedCards = temp;
                combinationType = STRAIGHT;
                getHighestCard();
            }
        }
    }
}

void Combination::isFlush(){
    bool isFlush = true;
    vector<ColorCard> temp;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getColor() != allCards[i+1].getColor()){
            isFlush = false;
            break;
        }
    }
    if(isFlush){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        temp.push_back(allCards[4]);
        if(inPlayer(temp)){
            if(combinationType <= FLUSH){
                usedCards = temp;
                combinationType = FLUSH;
                getHighestCard();
            }
        }
    }
}

void Combination::isFullHouse(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber() && allCards[1].getNumber() == allCards[2].getNumber() && allCards[3].getNumber() == allCards[4].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        temp.push_back(allCards[4]);
        if(inPlayer(temp)){
            if(combinationType <= FULL_HOUSE){
                usedCards = temp;
                combinationType = FULL_HOUSE;
                getHighestCard();
            }
        }
    }
}

void Combination::isStraightFlush(){
    bool isStraightFlush = true;
    vector<ColorCard> temp;
    for(int i = 0; i < 5; i++){
        if(allCards[i].getNumber() != allCards[i+1].getNumber() + 1 || allCards[i].getColor() != allCards[i+1].getColor()){
            isStraightFlush = false;
            break;
        }
    }
    if(isStraightFlush){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        temp.push_back(allCards[2]);
        temp.push_back(allCards[3]);
        temp.push_back(allCards[4]);
        if(inPlayer(temp)){
            if(combinationType <= STRAIGHT_FLUSH){
                combinationType = STRAIGHT_FLUSH;
                getHighestCard();
            }
        }
    }
}

bool Combination::inPlayer(vector<ColorCard> cards){
    for(int i = 0; i < cards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), cards[i]) != playerCards.end()){
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