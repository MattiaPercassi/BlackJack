#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "Dealer.h"
#include "Deck.h"
#include "RealPlayer.h"
#include "Match.h"
#include <random>
#include <ctime>
#include <limits>
#include <sstream>

// static data member must be declared outside the class of belonging (Deck) and need to be present in one single source file in the scope of their belonging (i.e. global scope). Here members are also initialized outside the class and within the class they are just declared.
// it is preferred to seed the pseudo random generator with the c-style time(nullptr) from <ctime> as the stl random_device CAN produce always the same seed depending on machine implementation, as it was in this case, this solution provides random suffles every time
std::mt19937 Deck::rng{static_cast<unsigned int>(time(nullptr))};

int main()
{

    Dealer dealer;
    dealer.setPlayer("Dealer", 0);

    std::cout << "\nWelcome to the BlackJack game\n\nHow many players are there? ";
    bool flag{false};
    int playerNumber{0};
    while (!flag)
    {
        std::string input;
        std::cin >> input;
        std::stringstream ss{input};
        if (ss >> playerNumber && playerNumber!=0)
        {
            std::cout << "\n"
                      << playerNumber << " players" << std::endl;
            flag = true;
        }
        else
        {
            std::cout << input << " is not a valid input, retry\nHow many players? ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
    std::vector<RealPlayer> players;
    for (int i{0}; i < playerNumber; ++i)
    {
        RealPlayer pl;
        std::cout << "What is the name of player " << i + 1 << "? ";
        std::string input;
        std::cin >> input;
        pl.setPlayer(input, 100);
        players.push_back(pl);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    };

    Deck deck{1};

    Match match1{dealer, players, deck, 5, 100, 5};

    while (match1.checkHandsPlayed() && match1.areActivePlayers())
    {
        std::cout << match1;
        match1.playhand();
    }
    std::cout << match1 << std::endl;

    // std::cout << deck << '\n';

    // while (deck.size() > 0)
    // {
    //     dealer.draw(deck);
    //     std::cout << deck;
    //     std::cout << '\n';
    // };

    /*
    std::vector<RealPlayer> players;
    size_t playerNum{5};
    int initialBalance{100};
    for (size_t i{0}; i < playerNum; ++i)
    {
        RealPlayer player;
        std::string name;
        std::cout << "Nome giocatore: ";
        std::cin >> name;
        player.setPlayer(name, initialBalance);
        players.push_back(player);
    };


    Match match1(dealer, players, deck);

    // code for playing the game
    */
    return 0;
};