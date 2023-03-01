#include "Game.hpp"

#include <iostream>

using namespace std;

Game::Game(){
    round =1;
}

void Game::start(){
    while (!isWinning()){
        newGame();
        while (!isRoundOver()){
            startRound();
        }
        endOfGame();
    }
}




