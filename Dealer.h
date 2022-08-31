#ifndef _DEALER_H_
#define _DEALER_H_

#include <string>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "RealPlayer.h"

class Dealer : public Player
{
public:
    Dealer() : Player(){};
    virtual ~Dealer(){};
    void setPlayer(std::string, int);
    void shuffle(Deck &);
    void win(RealPlayer &);
    void draw(Deck &);
    virtual void updateHandCounter();
};

#endif