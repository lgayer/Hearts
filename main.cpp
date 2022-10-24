#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <ctime>


int main()
{
	srand(time(nullptr));

	Deck deck;

	std::vector<Player> test;
	std::string name1, name2, name3, name4;
	std::cout << "Welcome. Please enter the names of the 4 players" << "\n";
	std::cin >> name1 >> name2 >> name3 >> name4;
	test.push_back(Player(name1));
	test.push_back(Player(name2));
	test.push_back(Player(name3));
	test.push_back(Player(name4));

	Game hearts = Game(test);
	while (hearts.CheckBust() == false)
	{
		hearts.Deal(deck);
		hearts.Round();
	}

	return 0;
}