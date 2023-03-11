#ifndef _PLAYABLE_HPP_
#define _PLAYABLE_HPP_

template <typename T>
class Playable
{
public:
    virtual T value() = 0;
};

#endif