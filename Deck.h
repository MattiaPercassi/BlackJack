#ifndef _DECK_H_
#define _DECK_H_

#include "Card.h"
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <random>

class Deck
{
    friend std::ostream &operator<<(std::ostream &, Deck &);

protected:
    std::vector<Card> cards;
    std::array<std::string, 4> suits{"Hearts", "Spades", "Flowers", "Squares"};
    std::array<std::string, 13> ranks{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::array<int, 13> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    int deckSize;
    static std::mt19937 rng;

public:
    Deck(int);
    Card draw();
    void addCards(std::vector<Card>);
    void shuffle();
    int size();
};

#endif