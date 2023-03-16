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
};

GetMostElement::getLowest(T[] array)
{
    T min = array[0];

    int length = size(array);
    for (int i = 1; i < length; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
};

template <typename T>
GetMostElement::getHighest(vector<T> vector)
{
    T max = vector.at(0);

    int length = array.size();
    for (int i = 1; i < length; i++)
    {
        if (array.at(i) > max)
        {
            max = array.at(i);
        }
    }
    return max;
}

GetMostElement::getLowest(vector<T> vector)
{
    T min = vector.at(0);

    int length = array.size();
    for (int i = 1; i < length; i++)
    {
        if (array.at(i) < min)
        {
            min = array.at(i);
        }
    }
    return min;
}