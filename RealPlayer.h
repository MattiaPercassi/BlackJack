#ifndef _REALPLAYER_H_
#define _REALPLAYER_H_

#include <string>
#include "Player.h"
#include "Card.h"
#include "Deck.h"

class RealPlayer : public Player
{
protected:
    int currentBet;

public:
    RealPlayer() : Player(), currentBet{} {};
    virtual ~RealPlayer(){};

    virtual void setPlayer(std::string, int);
    virtual void win(int);
    virtual void draw(Deck &);
    void bet(int);
    void resetBet();
};

#endif