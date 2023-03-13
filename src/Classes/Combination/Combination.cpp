#include "Combination.hpp"
#include <algorithm>
#include <vector>

Combination::Combo::Combo(){
    this->cards = Deck<ColorCard>();
    this->highestCard = ColorCard();
    this->cards+=this->highestCard;
}

Combination::Combo::Combo(Deck<ColorCard> cards){
    this->cards = cards;
    this->highestCard = cards.getDeck()[0]; // highest card is the first one, using heuristic
}

// ALL CHECKING IS USING HEURISTIC

bool Combination::Combo::isPair(){
    return this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber();
}

bool Combination::Combo::isTwoPairs(){
    return this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber() && this->cards.getDeck()[2].getNumber() == this->cards.getDeck()[3].getNumber();
}

bool Combination::Combo::isThreeOfAKind(){
    return this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber() && this->cards.getDeck()[1].getNumber() == this->cards.getDeck()[2].getNumber();
}

bool Combination::Combo::isStraight(){
    if(this->cards.getDeck().size() < 5) return false;
    for(int i = 0; i < 4; i++){
        if(this->cards.getDeck()[i].getNumber() != this->cards.getDeck()[i + 1].getNumber() - 1) return false;
    }
    return true;
}

bool Combination::Combo::isFlush(){
    if(this->cards.getDeck().size() < 5) return false;
    for(int i = 0; i < 4; i++){
        if(this->cards.getDeck()[i].getColor() != this->cards.getDeck()[i + 1].getColor()) return false;
    }
    return true;
}

bool Combination::Combo::isFullHouse(){
    return (this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber() && this->cards.getDeck()[1].getNumber() == this->cards.getDeck()[2].getNumber() && this->cards.getDeck()[3].getNumber() == this->cards.getDeck()[4].getNumber()) || (this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber() && this->cards.getDeck()[2].getNumber() == this->cards.getDeck()[3].getNumber() && this->cards.getDeck()[3].getNumber() == this->cards.getDeck()[4].getNumber());
}

bool Combination::Combo::isFourOfAKind(){
    return this->cards.getDeck()[0].getNumber() == this->cards.getDeck()[1].getNumber() && this->cards.getDeck()[1].getNumber() == this->cards.getDeck()[2].getNumber() && this->cards.getDeck()[2].getNumber() == this->cards.getDeck()[3].getNumber();
}

bool Combination::Combo::isStraightFlush(){
    return this->isStraight() && this->isFlush();
}

CombinationType Combination::Combo::getType(){
    if(this->isStraightFlush()) return STRAIGHT_FLUSH;
    if(this->isFourOfAKind()) return FOUR_OF_A_KIND;
    if(this->isFullHouse()) return FULL_HOUSE;
    if(this->isFlush()) return FLUSH;
    if(this->isStraight()) return STRAIGHT;
    if(this->isThreeOfAKind()) return THREE_OF_A_KIND;
    if(this->isTwoPairs()) return TWO_PAIRS;
    if(this->isPair()) return PAIR;
    return HIGH_CARD;
}

bool Combination::Combo::useOneOf(Deck<ColorCard> cards){
    switch(this->getType()){
        case STRAIGHT_FLUSH:
        case FULL_HOUSE:
        case FLUSH:
        case STRAIGHT:
            if(find(cards.getDeck().begin(), cards.getDeck().end(), this->cards.getDeck()[4]) != cards.getDeck().end()){
                return true;
            }
        case FOUR_OF_A_KIND:
        case TWO_PAIRS:
            if(find(cards.getDeck().begin(), cards.getDeck().end(), this->cards.getDeck()[3]) != cards.getDeck().end()){
                return true;
            }
        case THREE_OF_A_KIND:
            if(find(cards.getDeck().begin(), cards.getDeck().end(), this->cards.getDeck()[2]) != cards.getDeck().end()){
                return true;
            }
        case PAIR:
            for(int i = 0; i < 2; i++){
                if(find(cards.getDeck().begin(), cards.getDeck().end(), this->cards.getDeck()[i]) != cards.getDeck().end()){
                    return true;
                }
            }
        default:
            return false;
    }
}

Deck<ColorCard> Combination::Combo::getCards(){
    return this->cards;
}

ColorCard Combination::Combo::getHighestCard(){
    return this->highestCard;
}

bool Combination::Combo::operator<(Combination::Combo& other){
    CombinationType thisType = this->getType();
    CombinationType otherType = other.getType();
    return (thisType < otherType) || (thisType == otherType && this->getHighestCard() < other.getHighestCard());
}

bool Combination::Combo::operator>(Combination::Combo& other){
    CombinationType thisType = this->getType();
    CombinationType otherType = other.getType();
    return (thisType > otherType) || (thisType == otherType && this->getHighestCard() > other.getHighestCard());
}

bool Combination::Combo::operator==(Combination::Combo& other){
    CombinationType thisType = this->getType();
    CombinationType otherType = other.getType();
    return (thisType == otherType && this->getHighestCard() == other.getHighestCard());
}

void Combination::Combo::print(){
    std::cout << "Type: " << this->getType() << std::endl;
    std::cout << "Highest Card: "; this->highestCard.print(); std::cout << std::endl;
    std::cout << "Cards: ";
    for(int i = 0; i < this->cards.getDeck().size(); i++){
        this->cards.getDeck()[i].print();
    }
    std::cout << std::endl;
}

Combination::Combination(Deck<ColorCard> player, Deck<ColorCard> table){
    this->playerCards = player;
    this->allCards = player + table; allCards.sort(true);
    this->bestCombo = this->getBestCombo();
    this->highestPlayerCard = this->getHighestPlayerCard();
}

// refactor ini jadi ngecek highest card dan player card
Combination::Combo Combination::getBestCombo(){
    Combo bestCombo = Combo(this->allCards);
    while(prev_permutation(this->allCards.getDeck().begin(), this->allCards.getDeck().end())){
        Combo currentCombo = Combo(this->allCards);
        if((currentCombo > bestCombo || currentCombo == bestCombo) && bestCombo.useOneOf(this->playerCards)){
            bestCombo = currentCombo;
        }
    }
}

ColorCard Combination::getHighestPlayerCard(){
    ColorCard currHighestPlayerCard;
    for(int i = 0; i < this->playerCards.getDeck().size(); i++){
        if(find(this->bestCombo.getCards().getDeck().begin(), this->bestCombo.getCards().getDeck().end(), this->playerCards.getDeck()[i]) != this->bestCombo.getCards().getDeck().end() && this->playerCards.getDeck()[i] > currHighestPlayerCard){
            currHighestPlayerCard = this->playerCards.getDeck()[i];
        }
    }
}

void Combination::print(){
    std::cout << "Best Combo: " << std::endl;
    this->bestCombo.print();
    std::cout << "Highest Player Card: "; this->highestPlayerCard.print(); std::cout << std::endl;
}

bool operator<(Combination& first, Combination& second){
    return (first.bestCombo < second.bestCombo) || (first.bestCombo == second.bestCombo && first.highestPlayerCard < second.highestPlayerCard);
}

bool operator>(Combination& first, Combination& second){
    return (first.bestCombo > second.bestCombo) || (first.bestCombo == second.bestCombo && first.highestPlayerCard > second.highestPlayerCard);
}

bool operator==(Combination& first, Combination& second){
    return first.bestCombo == second.bestCombo && first.highestPlayerCard == second.highestPlayerCard;
}