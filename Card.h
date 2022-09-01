#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <vector>
#include <iostream>

class Card
{
    friend std::ostream &operator<<(std::ostream &, Card &);
    // for accumulate overloaded + operator with int on lhs is required
    friend int operator+(int &, Card &);

protected:
    int value;
    std::string suit;

public:
    Card(int val, std::string su) : value{val}, suit{su} {};
    int checkValue();
};

#endif