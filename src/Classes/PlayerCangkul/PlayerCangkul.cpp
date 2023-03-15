#include "PlayerCangkul.hpp"

int PlayerCangkul::num_player = 0;

PlayerCangkul::PlayerCangkul() : Player(num_player) {
    PlayerCangkul::num_player++;
}