#pragma once
#include<iomanip>

class Card
{
public:
	//List of Suits and Ranks as enumerators
	enum Suits
	{
		SPADES=1,
		DIAMONDS,
		CLUBS,
		HEARTS
	};

	enum Ranks
	{
		TWO=2,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
	};

	Card(Ranks RANK, Suits SUIT);
	virtual ~Card();

	int GetRank();
	int GetSuit();
	void Print();

	//overload = for finding specific cards
	bool operator == (const Card& c) {
		if (Suit == c.Suit && Rank == c.Rank)
			return true;
		return false;
	}

	//overload < for sorting hands
	bool operator < (Card& c) {
		if (Suit < c.Suit)
			return true;
		if (Suit == c.Suit &&  Rank < c.Rank)
			return true;
		return false;
	}

private:
	int Rank;
	int Suit;
};