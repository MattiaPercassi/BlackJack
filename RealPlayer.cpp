#include "RealPlayer.h"
#include <string>
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <iomanip>
#include <vector>

void RealPlayer::setPlayer(std::string nm, int initialBalance)
{
    name = nm;
    balance = initialBalance;
    eliminated = false;
    active = true;
};
void RealPlayer::win()
{
    // TODO - implement properly
    winning += currentBet;
    balance += currentBet * 2;
    resetBet();
};
void RealPlayer::lose()
{
    losses += currentBet;
    resetBet();
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
std::vector<Card> RealPlayer::returnCards()
{
    std::vector<Card> retCards = hand;
    hand.clear();
    return retCards;
};
std::ostream &operator<<(std::ostream &os, RealPlayer &rhs)
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
    os << "\nHand value: " << rhs.checkScore() << "\n\nCurrent balance: " << rhs.balance
       << "\nCurrent bet: " << rhs.currentBet << "\nHands played: " << rhs.handsPlayed << "\nEliminated: " << rhs.eliminated << "\nActive: " << rhs.active << std::endl;
    return os;
};