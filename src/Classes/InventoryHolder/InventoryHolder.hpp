#ifndef __INVENTORY_HOLDER_HPP_
#define __INVENTORY_HOLDER_HPP_

#include "Classes/Card/Card.hpp"

template <typename T>
class InventoryHolder
{
public:
    virtual void addCard(const T &) = 0;
};

#endif