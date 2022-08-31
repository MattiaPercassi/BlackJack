#include "Deck.h"
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <random>

Deck::Deck(int deckNum) : cards{}
{
    if (deckNum < 1)
        deckNum = 1;
    for (int i{0}; i < deckNum; ++i)
    {
        for (auto &su : suits)
        {
            for (auto &val : values)
            {
                cards.push_back(Card(val, su));
            }
        }
    }
    deckSize = cards.size();
    shuffle();
};

Card Deck::draw()
{
    Card card = cards.front();
    // erase won't erase the last element so we will call clear instead
    if (deckSize == 1)
        cards.clear();
    else
        cards.erase(cards.begin());
    --deckSize;
    return card;
};

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd()); // seed for random shuffle method
    std::shuffle(cards.begin(), cards.end(), g);
    return;
};

int Deck::size()
{
    return deckSize;
}

std::ostream &operator<<(std::ostream &os, Deck &rhs)
{
    if (rhs.deckSize == 0)
    {
        os << "Empty deck" << std::endl;
    }
    else
    {
        os << "Front card: " << rhs.cards.front() << "Total cards: " << rhs.cards.size() << std::endl;
    }
    return os;
};
