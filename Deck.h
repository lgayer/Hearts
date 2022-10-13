#pragma once

#include "Cards.h"
#include <vector>

class Deck
{
public:
	Deck();
	~Deck();

	void Print();
	void Shuffle();

	//Overloading[] to give access to cards in deck
	Card* operator [] (int i)
	{
		return deck[i];
	}

private:
	std::vector<Card*> deck;
};