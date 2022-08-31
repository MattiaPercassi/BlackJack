#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "Dealer.h"
#include "Deck.h"
#include "RealPlayer.h"
#include "Match.h"

int main()
{
    Dealer dealer;
    dealer.setPlayer("Dealer", 0);

    RealPlayer player1;
    RealPlayer player2;
    RealPlayer player3;
    RealPlayer player4;
    RealPlayer player5;
    player1.setPlayer("Mattia", 100);
    player2.setPlayer("Carlo", 100);
    player3.setPlayer("Matteo", 100);
    player4.setPlayer("Lucia", 100);
    player5.setPlayer("Giorgio", 100);
    std::vector<RealPlayer> players;
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    players.push_back(player4);
    players.push_back(player5);

    Deck deck{1};

    Match match1{dealer, players, deck, 10, 100, 10};

    while (match1.checkHandsPlayed())
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