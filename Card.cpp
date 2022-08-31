#include "Card.h"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, Card& card)
{
    os << card.value << " of " << card.suit;
    return os;
};