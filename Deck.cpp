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
            for (size_t j{0}; j < ranks.size(); ++j)
            {
                cards.push_back(Card(values.at(j), ranks.at(j), su));
            }
        }
    }
    deckSize = cards.size();
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
    // auto rng = std::default_random_engine{};
    // std::random_device rd;
    // std::mt19937 rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);
    return;
};

int Deck::size()
{
    return deckSize;
};
void Deck::addCards(std::vector<Card> retCards)
{
    for (auto &card : retCards)
    {
        cards.push_back(card);
    };
    deckSize += retCards.size();
};

std::ostream &operator<<(std::ostream &os, Deck &rhs)
{
    if (rhs.deckSize == 0)
    {
        os << "Empty deck" << std::endl;
    }
    else
    {
        os << "Front card: " << rhs.cards.front() << "\nTotal cards: " << rhs.cards.size() << std::endl;
    }
    return os;
};
