#include "Card.h"
#include <iostream>
#include <string>

int Card::checkValue()
{
    return value;
};

std::ostream &operator<<(std::ostream &os, Card &card)
{
    os << card.value << " of " << card.suit;
    return os;
};

int operator+(int &lhs, Card &rhs)
{
    return lhs + rhs.value;
}