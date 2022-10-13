#pragma once
#include "Cards.h"
#include "Deck.h"
#include <vector>
#include <string>

class Player
{
public:
	//Players Have Points for each round and a running total
	int RoundPoints = 0;
	int TotalPoints = 0;
	//Players have hands that store card pointers
	std::vector<Card*> Hand;
	//Vector to track the number of each suit in a players hand for legality checks on play
	std::vector<int> NumSuits;

	Player(std::string NAME);
	~Player();
	void IncreaseRoundPoints(int n);
	void IncreaseTotalPoints(int n);
	void PrintName();
	int GetRoundPoints();
	int GetTotalPoints();
	void DisplayHand();
	void SortHand();
	int CheckNumSuits(int i);
	void UpdateNumSuits();
	void ReduceNumSuits(int i);
	void PrintNumSuits();
	Card* PlayCard(int i);

private:
	std::string name;

};