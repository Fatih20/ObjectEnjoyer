#include "PlayerInGameCangkul.hpp"

PlayerInGameCangkul::PlayerInGameCangkul() : PlayerInGame<PlayerCangkul>(0){}

PlayerInGameCangkul::PlayerInGameCangkul(DeckGame<ColorCard> &deckGame, int numberOfPlayer) : PlayerInGame<PlayerCangkul> (numberOfPlayer) {
    for(int i = 0; i < numberOfPlayer; i++){
        createAndAddPlayer(i+1);
    }

    for (int i = 0; i < numberOfPlayer; i++)
    {
        this->players.at(turns.at(i)).drawCard(deckGame, 7); // 7 cards drawed
    }
}

PlayerInGameCangkul::PlayerInGameCangkul(const PlayerInGameCangkul &playerInGameCangkul) : PlayerInGame<PlayerCangkul>(playerInGameCangkul){

}

void PlayerInGameCangkul::showLeaderboard() {
    std::vector<PlayerCandy> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player<ColorCard> p1, Player<ColorCard> p2) -> bool { return p1 > p2; });
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ".";
        sortedPlayers.at(i).getScore();
    }
}

void resetRound(){
    PlayerInGame::resetRound();
    std::rotate(turns.begin(), turns.begin() + 1, turns.end());
}

void createAndAddPlayer(int gameID){
    PlayerCangkul p(gameID);
    while (usernameExist(p.getUsername()))
    {
        cout << "Username itu sudah dipakai! Pilih yang lain." << endl;
        p.setValidUsername();
    }
    players.push_back(p);
}

bool usernameExist(std::string username){
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = players.at(i).getUsername() == username;
    }
    return found;
}

bool usernameExist(std::string username, int gameID){
    bool found = false;
    for (int i = 0; i < players.size() && !found; i++)
    {
        found = players.at(i).getUsername() == username;
    }
    return found;
}

void showPlayerExceptCurrent(){
    vector<int> exceptedIndex = {getIndexOfCurrentTurn()};
    showPlayerExcept(exceptedIndex);
}

void showPlayerExcept(vector<int> exceptedIndex){
    int numberOfPlayer = getNumberOfPlayer();
//    int indexOfCurrentTurn = getIndexOfCurrentTurn();
    int numbering = 0;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        if (exceptedIndex.end() != find(exceptedIndex.begin(), exceptedIndex.end(), i))
        {
            cout << numbering + 1 << ". " << players.at(i) << endl;
            numbering++;
        }
    }
}

void removePlayerOfID(int removedID){
    auto iterator = find_if(this->players.begin(), this->players.end(), [removedID](PlayerCandy p) -> bool
    { return p.getGameID() == removedID; });

    if (iterator != this->players.end())
    {
        remove(iterator - this->players.begin());
    }
}

std::string getWinner(){
    // get winner (empty?)
}

bool winnerExist(){
    // all except one player deck is empty
    //loser exist? :)))))
    return false;
}