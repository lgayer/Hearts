#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include<ctime>


int main()
{
	srand(time(nullptr));

	Deck deck;

	std::vector<Player> test;
	test.push_back(Player("Luke1"));
	test.push_back(Player("Luke2"));
	test.push_back(Player("Luke3"));
	test.push_back(Player("Luke4"));

	Game hearts = Game(test);
	while (hearts.CheckBust() == false)
	{
		hearts.Deal(deck);
		hearts.Round();
	}

	return 0;
}