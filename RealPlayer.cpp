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
};
void RealPlayer::win()
{
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
bool RealPlayer::bet(int b)
{
    if (b <= balance)
    {
        balance -= b;
        currentBet += b;
        return true;
    }
    return false;
};
int RealPlayer::checkBalance()
{
    return balance;
};
int RealPlayer::checkBet()
{
    return currentBet;
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
    os << "-------------------\n"
       << rhs.name << '\n'
       << std::setw(20) << "Winning: " << std::left << rhs.winning << '\n'
       << std::setw(20) << "Losses: " << std::left << rhs.losses << '\n'
       << std::setw(20) << "Current hand: ";
    if (rhs.hand.size() == 0)
        os << std::left << "No cards";
    else
    {
        for (auto &card : rhs.hand)
        {
            os << card;
        };
    }
    os << '\n'
       << std::setw(20) << "Hand value: " << std::left << rhs.checkScore() << '\n'
       << '\n'
       << std::setw(20) << "Current balance: " << std::left << rhs.balance << '\n'
       << std::setw(20) << "Current bet: " << std::left << rhs.currentBet << '\n'
       << std::setw(20) << "Hands played: " << std::left << rhs.handsPlayed << '\n'
       << "-------------------" << std::endl;
    return os;
};