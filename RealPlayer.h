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

public:
    RealPlayer() : Player(), currentBet{} {};
    RealPlayer(std::string, int);
    virtual ~RealPlayer(){};

    virtual void setPlayer(std::string, int);
    void win();
    void lose();
    void even();
    virtual void draw(Deck &);
    virtual void updateHandCounter();
    void bet(int);
    int checkBalance();
    int checkBet();
    void resetBet();
    std::vector<Card> returnCards();
    void showHand();
};

#endif