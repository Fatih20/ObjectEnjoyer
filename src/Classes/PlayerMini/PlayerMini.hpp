#include "../Player/Player.hpp"

template <typename T>
class PlayerMini
{
private:
    string username;
    unsigned int score;

public:
    PlayerMini();
    PlayerMini(string username, int score);
    PlayerMini(const Player<T> &p);
    bool operator>(const PlayerMini<T> &p) const;
    unsigned int getScore() const;
    string getUsername() const;
};
