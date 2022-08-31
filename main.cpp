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
    std::cout << dealer;
    std::cout << std::endl;

    RealPlayer player;
    player.setPlayer("Mattia", 100);
    std::cout << player;
    std::cout << std::endl;
    int deckNum{1};
    Deck deck(deckNum);
    std::cout << deck;
    std::cout << std::endl;
    dealer.giveCard(deck,player);
    dealer.giveCard(deck,player);
    std::cout << player;
    std::cout << std::endl;
    dealer.draw(deck);
    dealer.draw(deck);
    std::cout << dealer;
    std::cout<<std::endl;
    player.bet(20);
    dealer.lose(player);
    std::cout << dealer << '\n' << player;
    std::cout << std::endl;
    dealer.collectCards(deck,player);
    dealer.returnCards(deck);
    std::cout << dealer << '\n' << player <<'\n' <<deck;
    std::cout << std::endl;
    player.bet(20);
    dealer.win(player);
    std::cout << dealer << '\n' << player;
    std::cout << std::endl;
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