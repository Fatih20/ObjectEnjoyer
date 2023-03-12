#include "ColorCard.hpp"
#include <iostream>

const std::map<std::pair<int, Color>, int> ColorCard::cardWeight = {
    {{0, GREEN}, -1}, {{0, BLUE}, -1}, {{0, YELLOW}, -1}, {{0, RED}, -1},
    {{1, GREEN}, 0}, {{1, BLUE}, 1}, {{1, YELLOW}, 2}, {{1, RED}, 3},
    {{2, GREEN}, 4}, {{2, BLUE}, 5}, {{2, YELLOW}, 6}, {{2, RED}, 7},
    {{3, GREEN}, 8}, {{3, BLUE}, 9}, {{3, YELLOW}, 10}, {{3, RED}, 11},
    {{4, GREEN}, 12}, {{4, BLUE}, 13}, {{4, YELLOW}, 14}, {{4, RED}, 15},
    {{5, GREEN}, 16}, {{5, BLUE}, 17}, {{5, YELLOW}, 18}, {{5, RED}, 19},
    {{6, GREEN}, 20}, {{6, BLUE}, 21}, {{6, YELLOW}, 22}, {{6, RED}, 23},
    {{7, GREEN}, 24}, {{7, BLUE}, 25}, {{7, YELLOW}, 26}, {{7, RED}, 27},
    {{8, GREEN}, 28}, {{8, BLUE}, 29}, {{8, YELLOW}, 30}, {{8, RED}, 31},
    {{9, GREEN}, 32}, {{9, BLUE}, 33}, {{9, YELLOW}, 34}, {{9, RED}, 35},
    {{10, GREEN}, 36}, {{10, BLUE}, 37}, {{10, YELLOW}, 38}, {{10, RED}, 39},
    {{11, GREEN}, 40}, {{11, BLUE}, 41}, {{11, YELLOW}, 42}, {{11, RED}, 43},
    {{12, GREEN}, 44}, {{12, BLUE}, 45}, {{12, YELLOW}, 46}, {{12, RED}, 47},
    {{13, GREEN}, 48}, {{13, BLUE}, 49}, {{13, YELLOW}, 50}, {{13, RED}, 51}
};

ColorCard::ColorCard(): Card<int>(0){
    this->color = GREEN;
}

ColorCard::ColorCard(int value, Color color): Card<int>(value){
    this->color = color;
}

Color ColorCard::getColor()
{
    return this->color;
}

std::string ColorCard::getColorAsString() const {
    return ColorCard::colorAsString(this->color);
}

int ColorCard::getNumber(){
    return this->Card::val;
}

int ColorCard::value(){
    return this->cardWeight.at(std::make_pair(this->Card::val, this->color));
}

void ColorCard::setColor(Color color)
{
    this->color = color;
}

void ColorCard::setValue(int value, Color color)
{
    Card *card = this;
    card->setValue(value);
    this->color = color;
}

std::string ColorCard::colorAsString(Color col) {
    std::string str;

    switch(col) {
        case 0:
            str = "GREEN";
            break;
        case 1:
            str = "BLUE";
            break;
        case 2:
            str = "YELLOW";
            break;
        case 3:
            str = "RED";
            break;
        default:
            str = "COLOR_UNKNOWN";
    }

    return str;
}

void ColorCard::operator=(const ColorCard &other)
{
    this->Card::val = other.Card::val;
    this->color = other.color;
}

void swap(ColorCard &a, ColorCard &b)
{
    ColorCard temp = a;
    a = b;
    b = temp;
}

bool ColorCard::operator==(ColorCard other)
{
    return this->value() == other.value();
}

bool operator<(ColorCard a, ColorCard b){
    return a.value() < b.value();
}

bool operator>(ColorCard a, ColorCard b){
    return a.value() > b.value();
}

std::ostream &operator<<(std::ostream &os, const ColorCard &card)
{
    os << card.Card::val << " " << card.getColorAsString() << std::endl;

    return os;
};

void ColorCard::print(){
    std::cout << *this;
}
