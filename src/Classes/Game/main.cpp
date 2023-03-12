#include "../GameCandy/GameCandy.hpp"
#include "../GameCapsa/GameCapsa.hpp"
#include "Game.hpp"
#include "../GameCandy/GameCandyException/GameCandyException.hpp"
#include <iostream>

using namespace std;

int main(){
    Game<int> *game;
    int opt;
    cout << "Game apah?\n";
    cout << "1. Candy\n";
    cout << "2. Capsa\n";
    cin >> opt;
    if (opt==1){
        game = new GameCandy<int>;
    } else {
        game = new GameCapsa<int>;
    }
    game->start();
    return 0;
}