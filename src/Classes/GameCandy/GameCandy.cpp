#include "GameCandy.hpp"

#include <iostream>

using namespace std;


template <typename T>
GameCandy<T>::GameCandy(): Game(),PlayerInGame(7){
    round=1; giftPoint=64;
}

template <typename T>
bool GameCandy<T>::isWinning(){
    // return (winningPlayer()!=0)
    return false;
}

template <typename T>
bool GameCandy<T>::isRoundOver(){
    // true jika semua player telah mendapat giliran
    return false;
}

template <typename T>
void GameCandy<T>::newGame(){
    // deck card baru
}

template <typename T>
void GameCandy<T>::endOfGame(){
    // i = winningPlayer();
    // players.at(i).addScore(giftPoint);
    giftPoint = 64;
}

template <typename T>
void GameCandy<T>::startRound(){
    switch (round)
    {
    case 1:
        //bagi color card
        break;
    case 2:
        //bagi ability card
    }

    for (int i=0; i<7; i++){
        int cmd = inputCommand();
        playerAction(cmd);
        // nextTurn();
    }
}

template <typename T>
void GameCandy<T>::playerAction(int cmd){
    // switch (cmd)
    // {
    // case 1:
    //     nextCommand();
    //     break;
    
    // default:
    //     break;
    // }
}


