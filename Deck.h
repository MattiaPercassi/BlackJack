#ifndef _DECK_H_
#define _DECK_H_

#include "Card.h"
#include <vector>
#include <array>
#include <iostream>
#include <string>

class Deck
{
    friend std::ostream &operator<<(std::ostream &, Deck &);

protected:
    std::vector<Card> cards;
    std::array<std::string, 4> suits{"Hearts", "Spades", "Flowers", "Squares"};
    std::array<int, 13> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int deckSize;

public:
    Deck(int);
    Card draw();
    void returnCard();
    void shuffle();
    int size();
};

#endif