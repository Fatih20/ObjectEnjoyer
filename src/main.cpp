#include "Classes/Player/Player.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
// #include "Classes/AbilityCard/AbilityCard.hpp"
#include "Classes/GameCandy/GameCandy.hpp"
#include "Classes/Combination/Combination.hpp"
#include "Classes/SplashScreen/SplashScreen.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    SplashScreen::splashScreenMain();
    Game *game;
    int opt=0;
    bool run = true;
    while (run){
        cout << "Select a game you want to play:\n"
             << "  1. Candy Game\n"
             << "  2. Cangkul\n"
             << "  3. Exit\n"
             << "> ";
        while(opt!=1&&opt!=2&&opt!=3){
            try {
                cin >> opt;
                if (opt!=1 && opt !=2 && opt!=3){
                    throw 505;
                }
            } catch (...){
                cout << "\nInvalid input, please enter 1/2/3\n";
            }
        }

        if (opt==1){
            game = new GameCandy();
            game->start();
        } else if (opt==2) {
            // game = new GameCangkul();
            // game->start();
        } else {
            run=false;
        }
    }
    

    // GameCandy game;
    // game.start();
    return 0;
}