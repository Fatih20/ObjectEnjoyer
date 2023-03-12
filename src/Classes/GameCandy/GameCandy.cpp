#include "GameCandy.hpp"

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


template <typename T>
GameCandy<T>::GameCandy() {
    splashScreen();
    round=1; giftPoint=64;
}

template <typename T>
void GameCandy<T>::start(){
    cout << "New game start\n";
    while (!isWinning()){
    // inisialisasi game baru -> player sama, deckCard baru
        cout << "Round " << round << " begin\n";
        newGame();
        while (!isRoundOver()){
            inputCommand();
        }
    }
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
//     switch (round)
//     {
//     case 1:
//         //bagi color card
//         break;
//     case 2:
//         //bagi ability card
//     }

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

template <typename T>
string GameCandy<T>::inputCommand(){
    string cmd;
    bool isValid=false;
    while (!isValid){
        try {
            cout << "> ";
            cin >> cmd;
            cout << isCommandValid(cmd) << endl;
            isCommandValid(cmd);
            isValid = true;
        } catch (CommandInvalid e){
            cout << "Command '" << e.getInvalidCommand() << "' is invalid\n\n";
        }
    }
    return cmd;
}

template <typename T>
string GameCandy<T>::isCommandValid(string userCommand){

    string oriCommand = userCommand;
    transform(userCommand.begin(),userCommand.end(),userCommand.begin(),::tolower);

    map<string,Command>::iterator it;
    it = cmd.find(userCommand);

    if (it != cmd.end()){
        //userCommand valid
        return it->first;
    } else{
        //userCommand invalid
        throw CommandInvalid(oriCommand);
    }
}

template <typename T>
void GameCandy<T>::splashScreen(){
    cout << "Game Candy Splash screen\n";
}

template GameCandy<int>::GameCandy();