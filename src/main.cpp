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
    // cout << "[deckA]" << endl;
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, RED);
    ColorCard cc3(3, BLUE);
    ColorCard cc4(4, YELLOW);
    ColorCard cc5(4, YELLOW);
    ColorCard cc6(4, YELLOW);
    ColorCard cc7(4, YELLOW);
    ColorCard cc8(4, YELLOW);
    ColorCard cc9(4, YELLOW);

    vector<ColorCard> vec;
    vec.push_back(cc1);
    vec.push_back(cc2);

    Deck<ColorCard> deckA(vec);
    deckA.addCard(cc1);
    deckA.addCard(cc2);
    deckA.addCard(cc3);
    deckA.addCard(cc4);
    deckA.addCard(cc5);
    deckA.addCard(cc6);
    deckA.addCard(cc7);
    deckA.addCard(cc8);
    deckA.addCard(cc9);

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

    cout << "Initialized" << endl;
    shared_ptr<Quadruple> quad = make_shared<Quadruple>();
    shared_ptr<Quarter> quarter = make_shared<Quarter>();
    shared_ptr<Quadruple> quad1 = make_shared<Quadruple>();
    shared_ptr<Quarter> quarter1 = make_shared<Quarter>();
    shared_ptr<Quadruple> quad2 = make_shared<Quadruple>();
    shared_ptr<Quarter> quarter2 = make_shared<Quarter>();
    shared_ptr<Quadruple> quad3 = make_shared<Quadruple>();
    cout << "Ability created" << endl;

    AbilityCard ac1(quad);
    AbilityCard ac2(quad2);
    AbilityCard ac3(quad3);
    AbilityCard ac4(quarter);
    AbilityCard ac5(quarter1);
    AbilityCard ac6(quarter2);
    AbilityCard ac7(quad1);

    AbilityCard ac22 = ac2;
    cout << ac22.value().get() << endl;
    cout << ac2.value().get() << endl;
    // cout << ac1 << endl;
    cout << ac2 << endl;
    cout << "Card created" << endl;

    vector<AbilityCard>
        abilityCards{ac5, ac6, ac1, ac2, ac3, ac4, ac7};
    cout << "Vector created" << endl;
    DeckGame<AbilityCard> deckAbility(abilityCards);
    cout << "First Deck created" << endl;

    DeckGame<ColorCard> deckA2 = deckA;

    cout << "Decks created" << endl;
    PlayerInGameCandy pigc(deckA2, deckAbility, 4);

    PlayerCandy p(9);
    cout << p.getAbilityName() << endl;
    p.drawAbility(deckAbility);
    p.test();

    PlayerCandy p2(10);
    cout << p2.getAbilityName() << endl;

    p2.drawAbility(deckAbility);
    p2.test();

    PlayerCandy p3(11);
    cout << p2.getAbilityName() << endl;
    p3.drawAbility(deckAbility);
    p3.test();
    return 0;
}