#include "Classes/FileReader/FileReader.hpp"

int main(){
    FileReader f("test.txt");
    f.read();
    vector <Card <int> > ab = f.getAbilityCardOrder();
    DeckGame <Card <int> > dc = f.getDeckOrder();
    return 0;
}