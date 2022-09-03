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
    std::string rank;
    std::string suit;

public:
    Card(int val, std::string rk, std::string su) : value{val}, rank(rk), suit{su} {};
    int checkValue();
};

#endif