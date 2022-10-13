#include "Cards.h"
#include <iostream>

Card::Card(Ranks RANK, Suits SUIT)
	: Rank(RANK),
	  Suit(SUIT)
{
	//nothing needed
}

Card::~Card()
{
	//nothing needed
}

int Card::GetRank()
{
	return Rank;
}

int Card::GetSuit()
{
	return Suit;
}

void Card::Print()
{
	if (Rank <= TEN)
	{
		std::cout << Rank;
	}
	else if (Rank == JACK)
	{
		std::cout << "J";
	}
	else if (Rank == QUEEN)
	{
		std::cout << "Q";
	}
	else if (Rank == KING)
	{
		std::cout << "K";
	}
	else if (Rank == ACE)
	{
		std::cout << "A";
	}

	if (Suit == HEARTS)
	{
		std::cout << "H";
	}
	else if (Suit == DIAMONDS)
	{
		std::cout << "D";
	}
	else if (Suit == CLUBS)
	{
		std::cout << "C";
	}
	else if (Suit == SPADES)
	{
		std::cout << "S";
	}
}

