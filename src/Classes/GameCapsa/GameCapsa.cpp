#include "GameCapsa.hpp"

#include <iostream>
using namespace std;

GameCapsa::GameCapsa(){
    splashScreen();
}

void GameCapsa::splashScreen(){
    cout << ".------..------..------..------..------.     .------..------..------..------." << endl;
    cout << "|C.--. ||A.--. ||P.--. ||S.--. ||A.--. |.-.  |G.--. ||A.--. ||M.--. ||E.--. |" << endl;
    cout << "| :/\\: || (\\/) || :/\\: || :/\\: || (\\/) ((5)) | :/\\: || (\\/) || (\\/) || (\\/) |" << endl;
    cout << "| :\\/: || :\\/: || (__) || :\\/: || :\\/: |'-.-.| :\\/: || :\\/: || :\\/: || :\\/: |" << endl;
    cout << "| '--'C|| '--'A|| '--'P|| '--'S|| '--'A| ((1)) '--'G|| '--'A|| '--'M|| '--'E|" << endl;
    cout << "`------'`------'`------'`------'`------'  '-'`------'`------'`------'`------'" << endl;
    cout << "/nGame starting..." << endl;
}

void GameCapsa::start(){
}

bool GameCapsa::isWinning(){
    // return (winningPlayer()!=0)
    return false;
}

void GameCapsa::newGame(){
    // deck card baru
}

void GameCapsa::endOfGame(){
}

void GameCapsa::startRound(){
}

void GameCapsa::playerAction(int cmd){
}

string GameCapsa::inputCommand(){
}

string GameCapsa::isCommandValid(string userCommand){

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
