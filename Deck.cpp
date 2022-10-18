#include "Deck.h"
#include<algorithm>
#include<iostream>

//initialise deck with 52 cards
Deck::Deck()
	: deck()
{
	deck.reserve(52);

	for (Card::Ranks r = Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1))
	{
		for (Card::Suits s = Card::SPADES; s <= Card::HEARTS; s = static_cast<Card::Suits>(static_cast<int>(s) + 1))
		{
			deck.push_back(new Card(r, s));
		}
	}
}

//ensure cards are also delted along with pointers
Deck::~Deck()
{
	deck.clear();
}

void Deck::Print()
{
	for (Card* card : deck)
	{
		card->Print();
		std::cout << " ";
	}
	std::cout << "\n";
}

void Deck::Shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}
