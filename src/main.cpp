#include "Classes/Player/Player.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
// #include "Classes/AbilityCard/AbilityCard.hpp"
#include "Classes/GameCandy/GameCandy.hpp"
#include "Classes/Combination/Combination.hpp"

#include <vector>
#include <iostream>

using namespace std;

void splashScreenMain()
{
    cout << "                  __                                _" << endl;
    cout << "                 [  |                              | | " << endl;
    cout << " _   _   __ .---. | | .---.  .--.  _ .--..--. .---.| | " << endl;
    cout << "[ \\ [ \\ [  / /__\\| |/ /'`\\/ .'`\\ [ `.-. .-. / /__\\| | " << endl;
    cout << " \\ \\/\\ \\/ /| \\__.,| || \\__.| \\__. || | | | | | \\__.|_| " << endl;
    cout << "  \\__/\\__/  '.__.[___'.___.''.__.'[___||__||__'.__.(_) " << endl;
    cout << "                                     ____                                         " << endl;
    cout << "                              .-\"    `-.      ,                               " << endl;
    cout << "                            .'          '.   /j\\                              " << endl;
    cout << "                           /              \\,/:/#\\                /\\           " << endl;
    cout << "                          ;              ,//' '/#\\              //#\\          " << endl;
    cout << "                          |             /' :   '/#\\            /  /#\\         " << endl;
    cout << "                          :         ,  /' /'    '/#\\__..--\"\"\"\"/    /#\\__      " << endl;
    cout << "                           \\       /'\'-._:__    '/#\\        ;      /#, \"\"\"---" << endl;
    cout << "                            `-.   / ;#\']\" ; \"\"\"--./#J       ':____...!     " << endl;
    cout << "                               `-/   /#\\  J  [;[;[;Y]         |      ;        " << endl;
    cout << "\"\"\"\"\"\"---....             __.--\"/    '/#\\ ;   "
            "  |     !    |   #! |        "
         << endl;
    cout << "             "
            "--.. _.--"
            "     /      ,/#\'-..____.;_,   |    |   '  |        "
         << endl;
    cout << "                   \"-.        :_....___,/#} \"####\" | '_.-\",   | #['  |        " << endl;
    cout << "                      '-._      |[;[;[;[;|         |.;'  /;\\  |      |        " << endl;
    cout << "                      ,   `-.   |        :     _   .;'    /;\\ |   #\" |        " << endl;
    cout << "                      !      `._:      _  ;   ##' .;'      /;\\|  _,  |        " << endl;
    cout << "                     .#\""
            "---..._    ';, |      .;{___     /;\\  ]#' |__....--"
         << endl;
    cout << "          .--.      ;'/#\\         \\    ]! |       \"| , \"\"\"--./_J    /         " << endl;
    cout << "         /  '%;    /  '/#\\         \\   !' :        |!# #! #! #|    :`.__      " << endl;
    cout << "        i__..'%] _:_   ;##J         \\      :\"#...._!   '  \"  \"|__  |    `--.._" << endl;
    cout << "         | .--\"\"\" !|\"\"\"\"  |\"\"\"----...J     | '##\"\" `-._       |  \"\"\"---.._    " << endl;
    cout << "     ____: |      #|      |         #|     |          \"]      ;   ___...-\"T,  " << endl;
    cout << "    /   :  :      !|      |   _______!_    |           |__..--;\"\"\"     ,;MM;  " << endl;
    cout << "   :____| :    .-.#|      |  /\\      /#\\   |          /'               ''MM;  " << endl;
    cout << "    |\"\"\": |   /   \\|   .----+  ;      /#\\  :___..--\"\";                  ,'MM; " << endl;
    cout << "   _Y--:  |  ;     ;.-'      ;  \\______/#: /         ;                  ''MM; " << endl;
    cout << "  /    |  | ;_______;     ____!  |\"##\"\"\"MM!         ;                    ,'MM;" << endl;
    cout << " !_____|  |  |\"#\"#\"|____.'\"\"##\"  |       :         ;                     ''MM  " << endl;
    cout << "  | \"\"\"\"--!._|     |##\"\"         !       !         :____.....-------\"\"\"\"\"\" |'" << endl;
    cout << "  |          :     |______                        ___!_ \"#\"\"#\"\"#\"\"\"#\"\"\"#\"\"\"|  " << endl;
    cout << "__|          ;     |MM\"MM\"\"\"\"\"---..._______...--\"\"MM\"MM]                   |   " << endl;
    cout << "  \"\\-.      :      |#                                  :                   |  " << endl;
    cout << "    /#'.    |      /##,                                !                   |  " << endl;
    cout << "   .',/'\\   |       #:#,                                ;       .==.       |  " << endl;
    cout << "  /\"\\'#\"\\',.|       ##;#,                               !     ,'||||',     |  " << endl;
    cout << "        /;/`:       ######,          ____             _ :     M||||||M     |  " << endl;
    cout << "       ###          /;\"\\.__\"-._   \"\"\"                   |===..M!!!!!!M_____|  " << endl;
    cout << "                           `--..`--.._____             _!_                    " << endl;
    cout << "                                          `--...____,=\"_.'`-.____        " << endl;
}

int main()
{
    // // cout << "[deckA]" << endl;
    // ColorCard cc1(1, GREEN);
    // ColorCard cc2(2, RED);
    // ColorCard cc3(3, BLUE);
    // ColorCard cc4(4, YELLOW);
    // vector<ColorCard> vec;
    // vec.push_back(cc1);
    // vec.push_back(cc2);

    // Deck<ColorCard> deckA(vec);
    // deckA.addCard(cc1);
    // deckA.addCard(cc2);
    // deckA.addCard(cc3);
    // deckA.addCard(cc4);
    // deckA.sort(true);
    // cout << deckA << endl;
    // // p5.printScore();

    // cout << "[deckB]" << endl;
    // cout << "shuffled" << endl;
    // DeckGame<ColorCard> deckB(deckA);
    // deckB.shuffle();
    // cout << deckB << endl;

    // // cout << "sorted" << endl;

    // deckB.sort();
    // cout << deckB << endl;

    // ColorCard ccdraw = deckB.ejectCard();

    // cout << "deck B" << endl;
    // cout << deckB << endl;
    // cout << "ejected card  : " << ccdraw << endl;

    // ColorCard ccdraw_dupe = ccdraw;
    // cout << "ejected card : ";
    // ccdraw_dupe.print();
    // cout << endl;

    // Deck<ColorCard> deckC;
    // deckB >> deckC;
    // cout << "deckB" << deckB << endl
    //      << "deckC" << deckC;

    // // card
    // cout << "CARD Combination section" << endl;
    // // input example : input these into terminal :
    // //            9 1
    // //            10 3
    // //            5 1
    // //            6 1
    // //            7 2
    // //            8 1
    // //            13 1

    // vector<ColorCard> player;
    // vector<ColorCard> table;
    // for (int i = 0; i < 2; i++)
    // {
    //     int value;
    //     int color;
    //     cin >> value >> color;
    //     player.push_back(ColorCard(value, Color(color)));
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     int value;
    //     int color;
    //     cin >> value >> color;
    //     table.push_back(ColorCard(value, Color(color)));
    // }
    // Combination comb(player, table);
    // comb.print();

    // Deck<ColorCard> deckD = deckB + deckC;
    // // ColorCard ccdraw = deckB.drawCard();

    // // cout << deckB << endl;
    // // cout << "drawed card  : " << ccdraw << endl;

    // cout << deckD << deckB << deckC << endl;
    GameCandy game;
    game.start();

    return 0;
}