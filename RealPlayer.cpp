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
    std::cout << "-------------------\n"
              << name << " wins " << currentBet << "!\n-------------------" << std::endl;
    winning += currentBet;
    balance += currentBet * 2;
    resetBet();
};
void RealPlayer::lose()
{
    std::cout << "-------------------\n"
              << name << " loses " << currentBet << "\n-------------------" << std::endl;
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
    balance -= b;
    currentBet += b;
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

void RealPlayer::showHand()
{
    std::cout << name << '\n';
    for (auto &c : hand)
    {
        std::cout << c;
    }
    std::cout << std::endl;
};