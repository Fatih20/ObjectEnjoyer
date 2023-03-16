#include "GetMostElement.hpp"

template <typename T>
T GetMostElement<T>::getHighest(T array[])
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

template <typename T>
T GetMostElement<T>::getLowest(T array[])
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
T GetMostElement<T>::getHighest(vector<T> vector)
{
    T max = vector.at(0);

    int length = vector.size();
    for (int i = 1; i < length; i++)
    {
        if (vector.at(i) > max)
        {
            max = vector.at(i);
        }
    }
    return max;
}

template <typename T>
T GetMostElement<T>::getLowest(vector<T> vector)
{
    T min = vector.at(0);

    int length = vector.size();
    for (int i = 1; i < length; i++)
    {
        if (vector.at(i) < min)
        {
            min = vector.at(i);
        }
    }
    return min;
}