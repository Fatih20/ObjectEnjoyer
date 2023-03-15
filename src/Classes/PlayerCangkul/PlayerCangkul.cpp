#include "PlayerCangkul.hpp"

PlayerCangkul::PlayerCangkul() : Player<ColorCard>() {}

PlayerCangkul::PlayerCangkul(int id) : Player<ColorCard>(id) {}

PlayerCangkul::PlayerCangkul(const PlayerCangkul &p) : Player<ColorCard>(p) {
    // belum ada private attribute
    this->hasWon = p.hasWon;
}

