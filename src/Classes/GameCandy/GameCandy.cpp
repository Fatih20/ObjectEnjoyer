#include "GameCandy.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T>
GameCandy<T>::GameCandy() {
    round=1; giftPoint=64;
}

template <typename T>
void GameCandy<T>::start(){
    while (!isWinning()){
    // inisialisasi game baru -> player sama, deckCard baru
        newGame();
        while (!isRoundOver()){


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
    try {
        cout << "> ";
        cin >> cmd;
        cout << "\n\n";
        transform(cmd.begin(),cmd.end(),cmd.begin(),::tolower);
        cout << cmd << endl;
        cout << isCommandValid(cmd) << endl;
        isCommandValid(cmd);
    } catch (CommandInvalid e){
        cout << "Command '" << e.getInvalidCommand() << "' is invalid\n";
    }
    return cmd;
}

template <typename T>
bool GameCandy<T>::isCommandValid(string userCommand){
    // define valid commands
    vector<string> command { "next", "re-roll", "double", "quadruple",
                             "half", "quarter", "reverse", "swapcard", 
                             "abilityless"};
    
    string oriCommand = userCommand;
    transform(userCommand.begin(),userCommand.end(),userCommand.begin(),::tolower);

    vector<string>::iterator it;
    it = find(command.begin(),command.end(),userCommand);

    if (it != command.end()){
        //userCommand found in command
        return true;
    } else{
        //userCommand not found in command
        throw CommandInvalid(oriCommand);
    }
}

// template<>
template GameCandy<int>::GameCandy();