#include "PlayerCangkul.hpp"

PlayerCangkul::PlayerCangkul() : Player<ColorCard>() {

}

PlayerCangkul::PlayerCangkul(int id) : Player<ColorCard>(id) {

}

bool PlayerCangkul::isWinner() {
    return this->Player::handCards.getNumberOfCards() == 0;
}

void PlayerCangkul::printCards() {
    cout << "trying print" << endl;
    cout << this->Player::handCards.getNumberOfCards();
}

void PlayerCangkul::playCard(int index) {
    this->Player::handCards.ejectCardIndex(index);
}