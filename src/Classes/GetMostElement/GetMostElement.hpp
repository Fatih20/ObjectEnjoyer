#include <iterator>
#include <vector>

using namespace std;

class GetMostElement
{
    template <typename T>
    T static getHighest(T[]){};

    template <typename T>
    T static getLowest(T[]){};

    template <typename T>
    T static getHighest(vector<T>){};

    template <typename T>
    T static getLowest(vector<T>){};
};