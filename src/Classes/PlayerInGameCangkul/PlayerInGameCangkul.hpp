#ifndef _PLAYERINGAME_CANGKUL_HPP_
#define _PLAYERINGAME_CANGKUL_HPP_

#include "PlayerInGame/PlayerInGame.hpp"
#include "PlayerCangkul/PlayerCangkul.hpp"

using namespace std;

class PlayerInGameCangkul : public PlayerInGame<PlayerCangkul> {
public:
    PlayerInGameCangkul();

    PlayerInGameCangkul(DeckGame<ColorCard> &deckGame, int numberOfPlayer);

    PlayerInGameCangkul(const PlayerInGameCangkul &playerInGameCangkul);

    void showLeaderboard();

    void resetRound();

    void createAndAddPlayer(int gameID);

    bool usernameExist(std::string username);

    bool usernameExist(std::string username, int gameID);

    void showPlayerExceptCurrent();

    void showPlayerExcept(vector<int> exceptedIndex);

    void removePlayerOfID(int removedID);

    std::string getWinner();

    bool winnerExist();

};

#endif