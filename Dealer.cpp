#include "Dealer.h"

void Dealer::setPlayer(std::string nm, int bal)
{
    name = nm;
    balance = bal;
};
void Dealer::shuffle(Deck &deck)
{
    deck.shuffle();
};
void Dealer::win(RealPlayer &player)
{
    winning += player.checkBet();
    player.lose();
};
void Dealer::lose(RealPlayer &player)
{
    losses += player.checkBet();
    player.win();
};
void Dealer::draw(Deck &deck)
{
    hand.push_back(deck.draw());
};
void Dealer::updateHandCounter()
{
    handsPlayed++;
};
std::ostream &operator<<(std::ostream &os, Dealer &rhs)
{
    os << std::boolalpha;
    os << rhs.name << "\nWinning: " << rhs.winning << "\nLosses: " << rhs.losses;
    os << "\nCurrent hand: ";
    if (rhs.hand.size() == 0)
        os << "No cards";
    else
    {
        for (auto &card : rhs.hand)
        {
            os << card << " | ";
        };
    }
    os << std::endl;
    return os;
};