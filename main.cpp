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
//	deck.Print();

//	Player POne = Player("Luke");
//	for (int i = 0; i < 13; i++)
//	{
//		POne.Hand.push_back(deck[i]);
//	}
//	POne.PrintName();
//	std::cout << "\n";
//	std::cout << "Hand: ";
//	POne.DisplayHand();
//	POne.SortHand();
//	std::cout << "Sorted: ";
//	POne.DisplayHand();
//	POne.UpdateNumSuits();
//	POne.PrintNumSuits();
//	Card* cardtest = POne.PlayCard(2);
//	std::cout << "You Played "; cardtest->Print(); std::cout << "\n";
//	POne.DisplayHand();
//	POne.PrintNumSuits();

	std::vector<Player> test;
	test.push_back(Player("Luke1"));
	test.push_back(Player("Luke2"));
	test.push_back(Player("Luke3"));
	test.push_back(Player("Luke4"));

	Game hearts = Game(test);
	hearts.Deal(deck);
	hearts.Round();

	return 0;
}