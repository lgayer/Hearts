#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include<ctime>


int main()
{
	srand(time(nullptr));

	Deck deck;
	deck.Print();
	deck.Shuffle();
	deck.Print();

	Player POne = Player("Luke");
	for (int i = 0; i < 13; i++)
	{
		POne.Hand.push_back(deck[i]);
	}
	POne.PrintName();
	std::cout << "\n";
	std::cout << "Hand: ";
	POne.DisplayHand();
	POne.SortHand();
	std::cout << "Sorted: ";
	POne.DisplayHand();
	POne.UpdateNumSuits();
	POne.PrintNumSuits();
	Card* test = POne.PlayCard(2);
	std::cout << "You Played "; test->Print(); std::cout << "\n";
	POne.DisplayHand();
	POne.PrintNumSuits();
	return 0;
}