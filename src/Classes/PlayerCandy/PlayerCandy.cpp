#include "PlayerCandy.hpp"

PlayerCandy::PlayerCandy(int id) : PlayerCandy()
{
    setGameID(id);
};

PlayerCandy::PlayerCandy() : Player<ColorCard>(){};