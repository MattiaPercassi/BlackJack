#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include "Dealer.h"
#include "Deck.h"
#include "RealPlayer.h"
#include "Match.h"

Match::Match(Dealer d, std::vector<RealPlayer> p, Deck de, int minbet, int maxbet, int maxhands) : dealer{d}, totalPlayers{static_cast<int>(p.size())}, activePlayers{p}, inactivePlayers{}, eliminatedPlayers{}, deck{de}, handCounter{0}, finished{false}, minimumBet{minbet}, maximumBet{maxbet}, maximumHands{maxhands} {};
void Match::playhand()
{
    // 1. dealer shuffles
    dealer.shuffle(deck);

    // 2. players bet
    for (auto &pl : activePlayers)
    {
        pl.bet(minimumBet);
    };

    // 3. dealer distributes cards and draws own cards
    for (auto &pl : activePlayers)
    {
        dealer.giveCard(deck, pl);
        dealer.giveCard(deck, pl);
    };
    dealer.draw(deck);
    dealer.draw(deck);

    // 4. player calls cards until limit or out
    for (auto &pl : activePlayers)
    {
        while (pl.checkScore() < 18)
            dealer.giveCard(deck, pl);
        std::cout << pl << std::endl;
    };

    // 5. dealer draws cards until limit or out
    while (dealer.checkScore() < 18)
    {
        dealer.draw(deck);
    };
    std::cout << dealer << std::endl;

    // 6. dealer wins and loses
    for (auto &pl : activePlayers)
    {
        if (dealer.checkScore() > 21 && pl.checkScore() <= 21)
            dealer.lose(pl);
        else if (pl.checkScore() > 21)
            dealer.win(pl);
        else if (dealer.checkScore() >= pl.checkScore())
            dealer.win(pl);
        else dealer.lose(pl);
    };

    // 7. dealer collect cards and return own cards to the deck
    for (auto &pl : activePlayers)
    {
        dealer.collectCards(deck, pl);
    };
    dealer.returnCards(deck);
    // TODO - implement code
    /*

    10. check the maximum hands, if reached we terminate here --> OUTSIDE THIS FUNCTION
    11. check if all players are eliminated if so we terminate --> OUTSIDE THIS FUNCTION
    end. show results of the match
    */

    // 8. update the played hands counter
    ++handCounter;
    // 9. eliminate players with too little balance
    for (auto &pl : activePlayers)
    {
        if (pl.checkBalance() < minimumBet)
        {
            eliminatedPlayers.push_back(pl);
        }
    }
    for (int i{static_cast<int>(activePlayers.size()) - 1}; i >= 0; i--)
    {
        if (activePlayers.at(i).checkBalance() < minimumBet)
            activePlayers.erase(activePlayers.begin() + i);
    };
    // lambda expression caputures this as this match object to evaluate the minimum bet
    // std::remove_if(activePlayers.begin(), activePlayers.end(), [this](RealPlayer &p)
    //                { return p.checkBalance() < this->minimumBet; });

    // 10. set all players not eliminated to activestatus for next hand
    for (auto &pl : inactivePlayers)
    {
        activePlayers.push_back(pl);
    }
    inactivePlayers.clear();
};

bool Match::checkHandsPlayed()
{
    return handCounter < maximumHands;
};

std::ostream &operator<<(std::ostream &os, Match &rhs)
{
    os << "----- CURRENT GAME STATUS -----" << '\n'
       << "Hands Played: " << rhs.handCounter << "/" << rhs.maximumHands << '\n'
       << "Active players: "
       << "Placeholder"
       << "/" << rhs.totalPlayers << '\n'
       << std::endl;
    return os;
};