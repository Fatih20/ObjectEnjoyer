#include "PlayerCangkul.hpp"

int PlayerCangkul::num_player = 0;

PlayerCangkul::PlayerCangkul() : Player(num_player + 1) {
    PlayerCangkul::num_player++;
}

bool PlayerCangkul::isWinner() {
    return this->Player::handCards.getNumberOfCards() == 0;
}

void PlayerCangkul::printCards() {
    cout << this->handCards;
}

void PlayerCangkul::playCard(int index) {
    this->Player::handCards.ejectCardIndex(index);
}