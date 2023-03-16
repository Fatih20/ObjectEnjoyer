#include "DeckGameCangkul.hpp"

DeckGameCangkul::DeckGameCangkul() : DeckGame<ColorCard>(){ }

DeckGameCangkul::DeckGameCangkul(std::vector<ColorCard> vec) : DeckGame<ColorCard>(vec){ }

DeckGameCangkul::DeckGameCangkul(const DeckGameCangkul &other) : DeckGame<ColorCard>(other){ }

bool DeckGameCangkul::isThereColor(Color color){
    std::vector<ColorCard> temp = this->getDeck();
    for (int i = 0 ; i < temp.size() ; i++){
        if(temp[i].getColor() == color){
            return true;
        }
    }
    return false;
}
