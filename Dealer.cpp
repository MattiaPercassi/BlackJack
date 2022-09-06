#include "Dealer.h"
#include <iomanip>

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
void Dealer::even(RealPlayer &player)
{
    player.even();
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
void Dealer::giveCard(Deck &deck, RealPlayer &player)
{
    player.draw(deck);
};
void Dealer::collectCards(Deck &deck, RealPlayer &player)
{
    deck.addCards(player.returnCards());
};
void Dealer::returnCards(Deck &deck)
{
    deck.addCards(hand);
    hand.clear();
};
void Dealer::updateHandCounter()
{
    handsPlayed++;
};
std::ostream &operator<<(std::ostream &os, Dealer &rhs)
{
    os << std::boolalpha;
    os << "-------------------\n"
       << rhs.name << '\n'
       << std::setw(20) << std::left << "Winning: " << rhs.winning << '\n'
       << std::setw(20) << std::left << "Losses: " << rhs.losses << '\n'
       << std::setw(20) << std::left << "Current hand: ";
    if (rhs.hand.size() == 0)
        os << "No cards";
    else
    {
        for (auto &card : rhs.hand)
        {
            os << card;
        };
    }
    os << '\n'
       << std::setw(20) << "Hand value: " << std::left << rhs.checkScore() << "\n-------------------\n";
    os << std::endl;
    return os;
};