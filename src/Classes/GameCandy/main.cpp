#include "GameCandy.cpp"
#include "../Game/Game.cpp"
#include "GameCandyException/GameCandyException.cpp"
#include <iostream>

using namespace std;

int main(){
    GameCandy<int> game;
    while (true){
        game.inputCommand();
    }
    return 0;
}