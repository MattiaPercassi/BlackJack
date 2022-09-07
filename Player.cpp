
#include "Player.h"
#include <string>
#include "Card.h"
#include <vector>
#include "Deck.h"
#include <algorithm>
#include <numeric>

Player::Player(std::string nm, int bl) : name{nm}, balance{bl}, winning{0}, losses{0}, handsPlayed{0} {};

int Player::checkScore()
{
    int tempScore{0};
    // No Ace score, sum all cards without Aces (lambda function dependent on the value assigned to ace)
    int acesCount = std::count_if(hand.begin(), hand.end(), [](Card &c)
                                  { return (c.checkValue() == 1); });
    for (auto &card : hand)
    {
        if (card.checkValue() != 1)
            tempScore += card.checkValue();
    };
    // if we are above 21 or we already checked all cards then the tempScore will be also the final one and should be returned
    if (tempScore > 21 || acesCount == 0)
        return tempScore;
    // if adding only aces counted as 1 we get 21 or higher, as this would be the minimum score we return the result
    if (tempScore + acesCount >= 21)
        return tempScore + acesCount;
    // if instead we do not reach 21 we have to check what happens when we consider aces as 11 and not 1 --> we start from the highest score so we will return only if we get below 21, if not after the for loop we will return the score calculated with minimum aceCount
    for (int i{acesCount}; i >= 1; --i)
    {
        int score{tempScore};
        score += i * 11 + acesCount - i;
        // since we start from the highest score, if this is less or equal to 21 wit is final
        if (score <= 21)
            return score;
    }
    // in case no combination was reached that could generate a score <=21
    return tempScore + acesCount;
};
int Player::countCards()
{
    return static_cast<int>(hand.size());
};