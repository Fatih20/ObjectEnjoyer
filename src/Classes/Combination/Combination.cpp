#include "Combination.hpp"

Combination::Combo::Combo()
{
    this->cards = Deck<ColorCard>();
    this->highestCard = ColorCard();
    this->cards += this->highestCard;
    this->type = setComboType();
}

Combination::Combo::Combo(Deck<ColorCard> cards)
{
    this->cards = cards;
    this->reduceCards(); // reduce cards to the number of cards needed for the combination
    this->highestCard = getHighestCardIntersection(this->cards);
}

void Combination::Combo::reduceCards()
{
    std::vector<ColorCard> cards = this->cards.getDeck();
    switch (this->getType())
    {
    case HIGH_CARD:
        cards.erase(cards.begin() + 1, cards.end());
        break;
    case PAIR:
        cards.erase(cards.begin() + 2, cards.end());
        break;
    case THREE_OF_A_KIND:
        cards.erase(cards.begin() + 3, cards.end());
        break;
    case TWO_PAIRS:
        cards.erase(cards.begin() + 4, cards.end());
        break;
    case FOUR_OF_A_KIND:
        cards.erase(cards.begin() + 4, cards.end());
        break;
    case FULL_HOUSE:
        cards.erase(cards.begin() + 5, cards.end());
        break;
    case STRAIGHT:
        cards.erase(cards.begin() + 5, cards.end());
        break;
    case FLUSH:
        cards.erase(cards.begin() + 5, cards.end());
        break;
    case STRAIGHT_FLUSH:
        cards.erase(cards.begin() + 5, cards.end());
        break;
    default:
        cards.erase(cards.begin() + 5, cards.end());
        break;
    }
    this->cards.setDeck(cards);
}

bool Combination::Combo::useOneOf(Deck<ColorCard> cards)
{
    std::vector<ColorCard> deck = this->cards.getDeck();
    std::vector<ColorCard> deck2 = cards.getDeck();
    for (int i = 0; i < deck.size(); i++)
    {
        if (find(deck2.begin(), deck2.end(), deck[i]) != deck2.end())
        {
            return true;
        }
    }
    return false;
}

ColorCard Combination::Combo::getHighestCardIntersection(Deck<ColorCard> cards)
{
    std::vector<ColorCard> deck = this->cards.getDeck();
    std::vector<ColorCard> deck2 = cards.getDeck();
    ColorCard highestCard = ColorCard();
    for (int i = 0; i < deck.size(); i++)
    {
        if (find(deck2.begin(), deck2.end(), deck[i]) != deck2.end() && deck[i] > highestCard)
        {
            highestCard = deck[i];
        }
    }
    return highestCard;
}

std::string Combination::Combo::getTypeString()
{
    switch (this->getType())
    {
    case STRAIGHT_FLUSH:
        return "Straight Flush";
    case FOUR_OF_A_KIND:
        return "Four of a Kind";
    case FULL_HOUSE:
        return "Full House";
    case FLUSH:
        return "Flush";
    case STRAIGHT:
        return "Straight";
    case THREE_OF_A_KIND:
        return "Three of a Kind";
    case TWO_PAIRS:
        return "Two Pairs";
    case PAIR:
        return "Pair";
    default:
        return "High Card";
    }
}

void Combination::Combo::print()
{
    std::cout << "Type: " << this->getTypeString() << std::endl;
    std::cout << "Highest Card: " << this->highestCard << std::endl;
    std::cout << this->cards;
}

Deck<ColorCard> Combination::Combo::getCards()
{
    return this->cards;
}

ColorCard Combination::Combo::getHighestCard()
{
    return this->highestCard;
}

CombinationType Combination::Combo::getType()
{
    // std::cout << "getting type\n";
    return this->type;
}

CombinationType Combination::Combo::setComboType()
{
    // std::cout << "setting type\n";
    if (this->isStraightFlush())
        return STRAIGHT_FLUSH;
    if (this->isFourOfAKind())
        return FOUR_OF_A_KIND;
    if (this->isFullHouse())
        return FULL_HOUSE;
    if (this->isFlush())
        return FLUSH;
    if (this->isStraight())
        return STRAIGHT;
    if (this->isThreeOfAKind())
        return THREE_OF_A_KIND;
    if (this->isTwoPairs())
        return TWO_PAIRS;
    if (this->isPair())
        return PAIR;
    return HIGH_CARD;
}

bool Combination::Combo::isStraightFlush()
{
    // std::cout << "isStraightFlush\n";
    return this->isStraight() && this->isFlush();
}

bool Combination::Combo::isFourOfAKind()
{
    // std::cout << "isFourOfAKind\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getNumber() == cards[1].getNumber() && cards[1].getNumber() == cards[2].getNumber() && cards[2].getNumber() == cards[3].getNumber();
}

bool Combination::Combo::isFullHouse()
{
    // std::cout << "isFullHouse\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    if (cards[0].getNumber() == cards[1].getNumber() && cards[1].getNumber() == cards[2].getNumber() && cards[3].getNumber() == cards[4].getNumber())
    {
        return true;
    }
    if (cards[0].getNumber() == cards[1].getNumber() && cards[2].getNumber() == cards[3].getNumber() && cards[3].getNumber() == cards[4].getNumber())
    {
        return true;
    }
    return false;
}

bool Combination::Combo::isFlush()
{
    // std::cout << "isFlush\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getColor() == cards[1].getColor() && cards[1].getColor() == cards[2].getColor() && cards[2].getColor() == cards[3].getColor() && cards[3].getColor() == cards[4].getColor();
}

bool Combination::Combo::isStraight()
{
    // std::cout << "isStraight\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getNumber() == cards[1].getNumber() - 1 && cards[1].getNumber() == cards[2].getNumber() - 1 && cards[2].getNumber() == cards[3].getNumber() - 1 && cards[3].getNumber() == cards[4].getNumber() - 1;
}

bool Combination::Combo::isThreeOfAKind()
{
    // std::cout << "isThreeOfAKind\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getNumber() == cards[1].getNumber() && cards[1].getNumber() == cards[2].getNumber();
}

bool Combination::Combo::isTwoPairs()
{
    // std::cout << "isTwoPairs\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getNumber() == cards[1].getNumber() && cards[2].getNumber() == cards[3].getNumber();
}

bool Combination::Combo::isPair()
{
    // std::cout << "isPair\n";
    std::vector<ColorCard> cards = this->cards.getDeck();
    return cards[0].getNumber() == cards[1].getNumber();
}

bool Combination::Combo::operator==(Combo rhs)
{
    return this->cards == rhs.getCards();
}

bool Combination::Combo::operator<(Combo rhs)
{
    return this->getType() < rhs.getType() || (this->getType() == rhs.getType() && this->cards < rhs.getCards());
}

bool Combination::Combo::operator>(Combo rhs)
{
    // std::cout << "Entering operator> for combo\n";
    return this->getType() > rhs.getType() || (this->getType() == rhs.getType() && this->cards > rhs.getCards());
}

bool Combination::Combo::operator<=(Combo rhs)
{
    return (*this < rhs) || (*this == rhs);
}

bool Combination::Combo::operator>=(Combo rhs)
{
    return (*this > rhs) || (*this == rhs);
}

Combination::Combination(Deck<ColorCard> cards)
{
    this->playerCards = cards;
    this->allCards = cards;
    allCards.sort(true);
    this->bestCombo = this->getBestCombo();
}

Combination::Combination(Deck<ColorCard> player, Deck<ColorCard> table)
{
    // std::cout << "Entering combination constructor" << std::endl;
    this->playerCards = player;
    this->allCards = table;
    this->allCards = this->allCards + player;
    // std::cout << "Initialized attributes. Now sorting cards." << std::endl;
    allCards.sort(true);
    // std::cout << "Sorting cards. Getting best combo." << std::endl;
    this->bestCombo = this->getBestCombo();
    // std::cout << "Got best combo. Exiting constructor." << std::endl;
}

void Combination::print()
{
    std::cout << "Player Cards: " << this->playerCards << std::endl;
    std::vector<ColorCard> tableCards = this->allCards.getDeck();
    std::vector<ColorCard> playerCards = this->playerCards.getDeck();
    tableCards.erase(remove_if(begin(tableCards), end(tableCards),
                               [&](auto x)
                               { return find(begin(playerCards), end(playerCards), x) != end(playerCards); }),
                     end(tableCards));
    Deck<ColorCard> table = Deck<ColorCard>(tableCards);
    std::cout << "Table Cards: " << table << std::endl;
    std::cout << "Best Combo: " << std::endl;
    this->bestCombo.print();
}

Combination::Combo Combination::getBestCombo()
{
    Combo bestCombo;
    std::vector<ColorCard> cards = this->allCards.getDeck();
    do
    {
        Combo combo = Combo(cards);
        if (combo >= bestCombo && combo.useOneOf(this->playerCards))
        {
            if (combo > bestCombo)
            {
                bestCombo = combo;
            }
            else if (combo == bestCombo)
            {
                if (combo.getHighestCardIntersection(this->playerCards) > bestCombo.getHighestCardIntersection(this->playerCards))
                {
                    bestCombo = combo;
                }
            }
        }
    } while (prev_permutation(cards.begin(), cards.end()));
    return bestCombo;
}

ColorCard Combination::getHighestPlayerCard()
{
    std::vector<ColorCard> cards = this->playerCards.getDeck();
    ColorCard bestCard = cards[0];
    for (int i = 1; i < cards.size(); i++)
    {
        if (cards[i] > bestCard)
        {
            bestCard = cards[i];
        }
    }
    return bestCard;
}

bool Combination::operator==(Combination rhs)
{
    return this->bestCombo == rhs.getBestCombo();
}

bool Combination::operator<(Combination rhs)
{
    return this->bestCombo < rhs.getBestCombo();
}

bool Combination::operator>(Combination rhs)
{
    // std::cout<<"Compare combination\n";
    return this->bestCombo > rhs.getBestCombo();
}

bool Combination::operator<=(Combination rhs)
{
    return (*this < rhs) || (*this == rhs);
}

bool Combination::operator>=(Combination rhs)
{
    return (*this > rhs) || (*this == rhs);
}