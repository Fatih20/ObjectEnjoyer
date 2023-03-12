#include "Classes/Player/Player.hpp"
#include "Classes/Deck/Deck.hpp"
#include "Classes/DeckGame/DeckGame.hpp"
#include "Classes/DeckPlayer/DeckPlayer.hpp"
#include "Classes/ColorCard/ColorCard.hpp"
#include "Classes/AbilityCard/AbilityCard.hpp"

#include <vector>

#include <iostream>

void splashScreen(){
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
cout << "                            `-.   / ;#\']\" ; \"\"\"--./#J       ':____...!     "   << endl;
cout << "                               `-/   /#\\  J  [;[;[;Y]         |      ;        " << endl;
cout << "\"\"\"\"\"\"---....             __.--\"/    '/#\\ ;   " "  |     !    |   #! |        " << endl;
cout << "             ""--.. _.--""     /      ,/#\'-..____.;_,   |    |   '  |        " << endl;
cout << "                   \"-.        :_....___,/#} \"####\" | '_.-\",   | #['  |        " << endl;
cout << "                      '-._      |[;[;[;[;|         |.;'  /;\\  |      |        " << endl;
cout << "                      ,   `-.   |        :     _   .;'    /;\\ |   #\" |        " << endl;
cout << "                      !      `._:      _  ;   ##' .;'      /;\\|  _,  |        " << endl;
cout << "                     .#\"""---..._    ';, |      .;{___     /;\\  ]#' |__....--" << endl;
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
    cout << "[deckA]" << endl;
    ColorCard cc1(1, GREEN);
    ColorCard cc2(2, RED);
    ColorCard cc3(3, BLUE);
    ColorCard cc4(4, YELLOW);
    Deck<ColorCard> deckA;
    deckA.addCard(cc1);
    deckA.addCard(cc2);
    deckA.addCard(cc3);
    deckA.addCard(cc4);
    cout << deckA << endl;
    // p5.printScore();


    cout << "[deckB]" << endl;
    cout << "shuffled" << endl;
    DeckGame<ColorCard> deckB(deckA);
    deckB.shuffle();
    cout << deckB << endl;

    cout << "sorted" << endl;
    deckB.sort();
    cout << deckB << endl;

    ColorCard ccdraw = deckB.drawCard();

    cout << deckB << endl;
    cout << "drawed card  : " << ccdraw << endl;



    return 0;
}