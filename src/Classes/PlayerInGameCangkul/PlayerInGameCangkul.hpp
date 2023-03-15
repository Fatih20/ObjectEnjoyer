#ifndef _PLAYERINGAME_CANGKUL_HPP_
#define _PLAYERINGAME_CANGKUL_HPP_

#include "PlayerInGame/PlayerInGame.hpp"
#include "PlayerCangkul/PlayerCangkul.hpp"

class PlayerInGameCangkul : public PlayerInGame<PlayerCangkul> {
public:
    PlayerInGameCangkul();

    PlayerInGameCangkul(DeckGame<ColorCard> &deckGame, int numberOfPlayer);

    PlayerInGameCangkul(const PlayerInGameCangkul &playerInGameCangkul);

    ~PlayerInGameCangkul();

    void removePlayerOfID(int removeID);

    void createAndAddPlayer(int id);

    bool usernameExist(std::string username);

    bool usernameExist(std::string username, int gameID);







};

#endif