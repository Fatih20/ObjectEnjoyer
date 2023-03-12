#ifndef _PLAYABLE_HPP_
#define _PLAYABLE_HPP_

template <typename T>
class Playable
{
public:
    virtual T value() const = 0;
};

#endif