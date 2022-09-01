#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "Card.h"
#include <vector>
#include "Deck.h"

// No need for dynamic polymorphism and virtual functions as we will not use pointer to base class in the program

class Player
{
protected:
    std::string name;
    int balance;
    int winning;
    int losses;
    int handsPlayed;
    bool eliminated;
    std::vector<Card> hand;

public:
    // initialize all at 0
    Player() : balance{0}, winning{0}, losses{0}, handsPlayed{0}, eliminated{false} {};

    // virtual destructor needed for syntax
    virtual ~Player(){};
    // copy / move constructors are not needed as no pointers are there in the members

    // /virtual functions to make the Player class abstract
    virtual void setPlayer(std::string, int) = 0;
    virtual void draw(Deck &) = 0;
    virtual void updateHandCounter() = 0;
    virtual int checkScore() = 0;
};

#endif