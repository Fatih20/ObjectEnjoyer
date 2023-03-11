#include "ComboMain.hpp"

template <typename T>
int ComboMain::getCombinationWeight(const DeckGame<T>& a, const DeckPlayer<T>& b) {
    return 0;
}

template int ComboMain::getCombinationWeight(const DeckGame<ColorCard> &a, const DeckPlayer<ColorCard> &b);