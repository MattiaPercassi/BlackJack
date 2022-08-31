#ifndef _MATCH_H_
#define _MATCH_H_

#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "Dealer.h"
#include "Deck.h"
#include "RealPlayer.h"

class Match
{
    friend std::ostream &operator<<(std::ostream &, Match &);

protected:
    Dealer dealer;
    std::vector<RealPlayer> players;
    Deck deck;
    int handCounter;
    bool finished;
    int minimumBet;
    int maximumBet;
    int maximumHands;

public:
    Match(Dealer, std::vector<RealPlayer>, Deck, int, int, int);
    void playhand();
    bool checkHandsPlayed();
    // void save(); //commented for now
};

#endif