#include "PlayerCangkul.hpp"

PlayerCangkul::PlayerCangkul() : Player<ColorCard>() {

}

PlayerCangkul::PlayerCangkul(int id) : Player<ColorCard>(id) {

}

void PlayerCangkul::updatePlayableDeck() {
    PlayerCangkul::resetPlayableDeck();

    for (int i = PlayerCangkul::handCards.getNumberOfCards() - 1; i >= 0; i--){
        PlayerCangkul::handCards >> PlayerCangkul::playableDeck;
    }
}

void PlayerCangkul::updatePlayableDeck(Color color) {
    PlayerCangkul::resetPlayableDeck();

    for (int i = PlayerCangkul::handCards.getNumberOfCards() - 1; i >= 0; i--){
        if(PlayerCangkul::handCards.getDeck()[i].getColor() == color){
            PlayerCangkul::playableDeck << PlayerCangkul::handCards.ejectCardIndex(i); // baru
        }
    }
}

void PlayerCangkul::resetPlayableDeck() {
    for(int i = 0; i < PlayerCangkul::getNumberOfPlayableCard(); i++){
        PlayerCangkul::playableDeck >> PlayerCangkul::handCards;
    }
}

void PlayerCangkul::printPlayableCard() {
    bool printed = false;

    vector<ColorCard> playableVec = PlayerCangkul::playableDeck.getDeck();
    cout << "|  ";

    int j = 1;
    for (auto i = playableVec.begin(); i != playableVec.end(); ++i)
    {
        cout << j << ". " << *i;
        printed = true;

        j++;
    }

    if(!printed){
        cout << "No card matched the color Filter!";
    }

    cout << endl;
}

ColorCard PlayerCangkul::ejectPlayableDeck(int index) {
    return PlayerCangkul::playableDeck.ejectCardIndex(index);
}

bool PlayerCangkul::isWinner() {
    return Player::handCards.getNumberOfCards() + PlayerCangkul::playableDeck.getNumberOfCards() == 0;
}

// TODO : remove
ColorCard PlayerCangkul::playCard(int index) {
    return PlayerCangkul::playableDeck.ejectCardIndex(index);
}

int PlayerCangkul::getNumberOfPlayableCard(){
    return PlayerCangkul::playableDeck.getNumberOfCards();
}