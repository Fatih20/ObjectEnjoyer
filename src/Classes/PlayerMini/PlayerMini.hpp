#include "../Player/Player.hpp"

template <typename T>
class PlayerMini
{
private:
    string username;
    long long score;

public:
    PlayerMini();
    PlayerMini(string username, long long score);
    PlayerMini(const Player<T> &p);
    bool operator>(const PlayerMini<T> &p) const;
    long long getScore() const;
    string getUsername() const;
};
