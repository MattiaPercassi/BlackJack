#ifndef _REALPLAYER_H_
#define _REALPLAYER_H_

#include <string>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>

class RealPlayer : public Player
{
    friend std::ostream &operator<<(std::ostream &, RealPlayer &);

protected:
    int currentBet;
    // Active player in current hand
    bool active;

public:
    RealPlayer() : Player(), currentBet{} {};
    virtual ~RealPlayer(){};

    virtual void setPlayer(std::string, int);
    void win();
    void lose();
    virtual void draw(Deck &);
    virtual void updateHandCounter();
    void bet(int);
    bool isActive();
    int checkBalance();
    int checkBet();
    bool isEliminated();
    void resetBet();
};

#endif