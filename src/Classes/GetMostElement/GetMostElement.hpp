#include <iterator>

using namespace std;

class GetMostElement
{
    template <typename T>
    T static getHighest(T[]){};

    template <typename T>
    T static getLowest(T[]){};
};