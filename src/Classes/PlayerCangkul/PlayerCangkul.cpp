#include "PlayerCangkul.hpp"

PlayerCangkul::PlayerCangkul() : Player<ColorCard>() {

}

PlayerCangkul::PlayerCangkul(int id) : Player<ColorCard>(id) {

}

void PlayerCangkul::updatePlayableDeck(Color color) {
    for (int i = PlayerCangkul::handCards.getNumberOfCards() - 1; i >= 0; i--){
        if(PlayerCangkul::handCards.getDeck()[i].getColor() == color){
//            PlayerCangkul::handCards >> PlayerCangkul::playableDeck;
        }
    }
}

void PlayerCangkul::resetPlayableDeck() {
//    for(int i = 0; i < PlayerCangkul::getNumberOfPlayableCard(); i++){
//        PlayerCangkul::playableDeck >> PlayerCangkul::handCards;
//    }
}

bool PlayerCangkul::isWinner() {
//    return Player::handCards.getNumberOfCards() + PlayerCangkul::playableDeck.getNumberOfCards() == 0;
    return 0;
}

// TODO : remove
void PlayerCangkul::playCard(int index) {
    this->Player::handCards.ejectCardIndex(index);
}

int PlayerCangkul::getNumberOfPlayableCard(){
//    return PlayerCangkul::playableDeck.getNumberOfCards();
    return 0;
}
