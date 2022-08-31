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
    player.resetBet();
};
void Dealer::draw(Deck &deck)
{
    hand.push_back(deck.draw());
};
void Dealer::updateHandCounter()
{
    handsPlayed++;
};