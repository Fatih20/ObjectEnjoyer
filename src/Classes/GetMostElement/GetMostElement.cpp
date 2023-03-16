#include "GetMostElement.hpp"

template <typename T>
GetMostElement::getHighest(T[] array)
{
    T max = array[0];

    int length = size(array);
    for (int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

GetMostElement::getLowest(T[] array)
{
    T max = array[0];

    int length = size(array);
    for (int i = 1; i < length; i++)
    {
        if (array[i] < max)
        {
            max = array[i];
        }
    }
    return max;
}