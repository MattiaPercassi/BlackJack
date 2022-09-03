#include "Card.h"
#include <iostream>
#include <string>
#include <iomanip>

int Card::checkValue()
{
    return value;
};

std::ostream &operator<<(std::ostream &os, Card &card)
{
    os << card.rank << " of " << std::setw(10) << std::left << card.suit;
    return os;
};

int operator+(int &lhs, Card &rhs)
{
    return lhs + rhs.value;
}