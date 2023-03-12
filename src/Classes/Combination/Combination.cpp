#include "Combination.hpp"
#include <algorithm>
#include <iostream>

bool operator>= (vector<ColorCard> a, vector<ColorCard> b){
    sort(a.begin(), a.end(), [](ColorCard a, ColorCard b){
        return a.value() > b.value();
    });
    sort(b.begin(), b.end(), [](ColorCard a, ColorCard b){
        return a.value() > b.value();
    });
    cout << "a: ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i].value() << " ";
    }
    cout << endl;
    cout << "b: ";
    for(int i = 0; i < b.size(); i++){
        cout << b[i].value() << " ";
    }
    cout << endl;
    if(a.size() > b.size()){
        return true;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]){
            return false;
        }
    }
    return true;
}

Combination::Combination(vector<ColorCard> player, vector<ColorCard> table){
    combinationType = HIGH_CARD;
    playerCards = player;
    allCards = player;
    allCards.insert(allCards.end(), table.begin(), table.end());
    sort(allCards.begin(), allCards.end(), [](ColorCard a, ColorCard b){
        return a.value() > b.value();
    });
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
        sort(playerCards.begin(), playerCards.end(), [](ColorCard a, ColorCard b){
            return a.value() > b.value();
        });
        usedCards.push_back(playerCards[0]);
    }
}

void Combination::isOnePair(){
    vector<ColorCard> temp;
    if(allCards[0].getNumber() == allCards[1].getNumber()){
        temp.push_back(allCards[0]);
        temp.push_back(allCards[1]);
        if(inPlayer(temp)){
            if(combinationType <= PAIR && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                combinationType = PAIR;
                usedCards = temp;
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
            if(combinationType <= TWO_PAIRS && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = TWO_PAIRS;
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
            if(combinationType <= THREE_OF_A_KIND && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = THREE_OF_A_KIND;
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
            if(combinationType <= FOUR_OF_A_KIND && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = FOUR_OF_A_KIND;
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
            if(combinationType <= STRAIGHT && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = STRAIGHT;
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
            if(combinationType <= FLUSH && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = FLUSH;
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
            if(combinationType <= FULL_HOUSE && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = FULL_HOUSE;
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
            if(combinationType <= STRAIGHT_FLUSH && highestCard.value() <= allCards[0].value() && highestPlayerCard.value() <= getHighestPlayerCard(temp).value() && temp >= getUsedCards()){
                highestPlayerCard = getHighestPlayerCard(temp);
                highestCard = allCards[0];
                usedCards = temp;
                combinationType = STRAIGHT_FLUSH;
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

ColorCard Combination::getHighestPlayerCard(vector<ColorCard> cards){
    ColorCard highest;
    for(int i = 0; i < cards.size(); i++){
        if(find(playerCards.begin(), playerCards.end(), cards[i]) != playerCards.end() && cards[i].value() >= highest.value()){
            highest = cards[i];
            // cout << "highest player card: " << highest.getNumber() << " " << highest.getColor() << endl;
            // cout << "card [i]: " << cards[i].getNumber() << " " << cards[i].getColor() << endl;
        }
    }
    return highest;
}

vector <ColorCard> Combination::getUsedCards(){
    return usedCards;
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
    cout<<"Highest Card: "<<highestCard.getNumber()<<" "<<highestCard.getColor()<<endl;
    cout<<"Highest Player Card: "<<highestPlayerCard.getNumber()<<" "<<highestPlayerCard.getColor()<<endl;
    cout<<"Used Cards: "<<endl;
    for(int i = 0; i < usedCards.size(); i++){
        usedCards[i].print();
    }
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
        vector<ColorCard> otherCards = other.getUsedCards();
        sort(usedCards.begin(), usedCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        sort(otherCards.begin(), otherCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        for(int i = 0; i < usedCards.size(); i++){
            if(usedCards[i].value() < otherCards[i].value()){
                return true;
            }
            else if(usedCards[i].value() > otherCards[i].value()){
                return false;
            }
        }
    }
    return false;
}

bool Combination::operator>(Combination& other){
    if(this->combinationType > other.combinationType){
                return true;
    }
    else if(this->combinationType == other.combinationType){
        vector<ColorCard> otherCards = other.getUsedCards();
        sort(usedCards.begin(), usedCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        sort(otherCards.begin(), otherCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        for(int i = 0; i < usedCards.size(); i++){
            if(usedCards[i].value() > otherCards[i].value()){
                return true;
            }
            else if(usedCards[i].value() < otherCards[i].value()){
                return false;
            }
        }
    }
    return false;
}

bool Combination::operator==(Combination& other){
    if(this->combinationType == other.combinationType){
        vector<ColorCard> otherCards = other.getUsedCards();
        sort(usedCards.begin(), usedCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        sort(otherCards.begin(), otherCards.end(), [](ColorCard a, ColorCard b){return a.getNumber() < b.getNumber();});
        for(int i = 0; i < usedCards.size(); i++){
            if(usedCards[i].value() != otherCards[i].value()){
                return false;
            }
        }
        return true;
    }
    return false;
}