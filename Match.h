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
protected:
    Dealer dealer;
    std::vector<RealPlayer> players;
    Deck deck;
    int handCounter;
    bool finished;

public:
    Match(Dealer, std::vector<RealPlayer>, Deck);
    void playhand();
    void showResults();
    bool isFinished();
    // void save(); //commented for now
};

#endif