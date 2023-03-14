#include "Game.hpp"

#include <iostream>

using namespace std;

Game::Game(){
}

void Game::splashScreen(){
    cout << "Game splash screen\n\n";
}

int Game::inputOption(int optionRange){
    int option;
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            cout << "> ";
            cin >> option;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                throw  OptionInvalid(optionRange);
            }
            isOptionValid(option, optionRange);
            isValid = true;
        }
        catch(OptionInvalid e)
        {
            cout << "\nInvalid input, please enter a number from 1-" << e.getValidOption() <<endl;
        }
        
    }
    return option;
}

bool Game::isOptionValid(int option,int optionRange){
    if(option>=1 && option<=optionRange){
        return true;
    } else {
        throw OptionInvalid(optionRange);
    }
}


