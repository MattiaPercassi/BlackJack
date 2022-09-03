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

    // 3. dealer distributes cards and draws own cards
    for (auto &pl : players)
    {
        dealer.giveCard(deck, pl);
        dealer.giveCard(deck, pl);
    };
    dealer.draw(deck);
    dealer.draw(deck);

    // 4. player calls cards until limit or out
    for (auto &pl : players)
    {
        while (pl.checkScore() < 18)
            dealer.giveCard(deck, pl);
        std::cout << pl << std::endl;
    };

    // 5. dealer draws cards until limit or out
    while (dealer.checkScore() < 18)
    {
        dealer.draw(deck);
        std::cout << dealer << std::endl;
    };

    // 6. dealer wins and loses
    for (auto &pl : players)
    {
        if (dealer.checkScore() > 21 && pl.checkScore() <= 21)
            dealer.lose(pl);
        else if (pl.checkScore()>21) dealer.win(pl);
        else if (dealer.checkScore()>=pl.checkScore()) dealer.win(pl);
    };

    // 7. dealer collect cards and return own cards to the deck
    for (auto &pl : players)
    {
        dealer.collectCards(deck, pl);
    };
    dealer.returnCards(deck);
    // TODO - implement code
    /*
    9. eliminate players with too little balance

    10. check the maximum hands, if reached we terminate here --> OUTSIDE THIS FUNCTION
    11. check if all players are eliminated if so we terminate --> OUTSIDE THIS FUNCTION
    end. show results of the match
    */
    // 8. update the played hands counter
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