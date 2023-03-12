#include "Game.hpp"

#include <iostream>

using namespace std;

template <typename T>
Game<T>::Game(){
}

template <typename T>
void Game<T>::splashScreen(){
    cout << "Game splash screen\n\n";
}

template Game<int>::Game();




