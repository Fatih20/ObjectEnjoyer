#include <iterator>
#include <vector>

using namespace std;

template <typename T>
class GetMostElement
{
    static T getHighest(T[]);

    static T getLowest(T[]);

    static T getHighest(vector<T>);

    static T getLowest(vector<T>);
};