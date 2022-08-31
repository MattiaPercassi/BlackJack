#include "RealPlayer.h"
#include <string>
#include "Card.h"
#include "Deck.h"
#include <iostream>

void RealPlayer::setPlayer(std::string nm, int initialBalance)
{
    name = nm;
    balance = initialBalance;
};
void RealPlayer::win()
{
    // TODO - implement properly
    winning += currentBet;
    balance += currentBet;
};
void RealPlayer::draw(Deck &deck)
{
    hand.push_back(deck.draw());
};
void RealPlayer::updateHandCounter()
{
    ++handsPlayed;
};
void RealPlayer::bet(int b)
{
    if (b <= balance)
    {
        balance -= b;
        currentBet += b;
        active = true;
    }
    else
    {
        active = false;
    };
};
bool RealPlayer::isActive()
{
    return active;
};
int RealPlayer::checkBalance()
{
    return balance;
};
int RealPlayer::checkBet()
{
    return currentBet;
};
bool RealPlayer::isEliminated()
{
    return eliminated;
};
void RealPlayer::resetBet()
{
    currentBet = 0;
};

std::ostream &operator<<(std::ostream &os, RealPlayer &rhs)
{
    os << rhs.name << '\n'
       << "Current hand: ";
    if (rhs.hand.size() == 0)
        os << "No cards";
    else
    {
        for (auto &card : rhs.hand)
        {
            os << card << " | ";
        };
    }
    os << '\n';
    os << "Current balance: " << rhs.balance << '\n'
       << "Current bet: " << rhs.currentBet << std::endl;
    return os;
};