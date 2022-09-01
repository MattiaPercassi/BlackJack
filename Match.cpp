#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include "Dealer.h"
#include "Deck.h"
#include "RealPlayer.h"
#include "Match.h"

Match::Match(Dealer d, std::vector<RealPlayer> p, Deck de, int minbet, int maxbet, int maxhands) : dealer{d}, players{p}, deck{de}, handCounter{0}, finished{false}, minimumBet{minbet}, maximumBet{maxbet}, maximumHands{maxhands} {};
void Match::playhand()
{
    // 1. dealer shuffles
    dealer.shuffle(deck);
    // 2. players bet
    for (auto &pl : players)
    {
        pl.bet(minimumBet);
    };
    // 3. dealer distributes cards
    for (auto &pl : players)
    {
        dealer.giveCard(deck, pl);
        dealer.giveCard(deck, pl);
    };

    // TODO - implement code
    /*
    4. player calls cards until limit or out
    .. [loop all players]
    5. dealer draws cards until limit or out
    6. dealer wins and loses
    7. cards are returned to the deck
    8. update the played hands counter
    9. eliminate players with too little balance

    10. check the maximum hands, if reached we terminate here --> OUTSIDE THIS FUNCTION
    11. check if all players are eliminated if so we terminate --> OUTSIDE THIS FUNCTION
    end. show results of the match
    */
    ++handCounter;
};

bool Match::checkHandsPlayed()
{
    return handCounter < maximumHands;
};

std::ostream &operator<<(std::ostream &os, Match &rhs)
{
    os << "----- CURRENT GAME STATUS -----" << '\n'
       << "Hands Played: " << rhs.handCounter << "/" << rhs.maximumHands << '\n'
       << "Active players: " << std::count_if(rhs.players.begin(), rhs.players.end(), [](RealPlayer &p)
                                              { return !p.isEliminated(); })
       << "/" << rhs.players.size() << std::endl;
    return os;
};