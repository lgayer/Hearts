#include "Cards.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Player.h"

//Initialise Player with Vector of 0s with length 4
Player::Player(std::string NAME)
	:name(NAME)
{
	for (int i = 0; i < 4; i++)
	{
		NumSuits.push_back(0);
	}
}

//Delete Vector
Player::~Player()
{
	NumSuits.clear();
}

//basic functions
void Player::IncreaseRoundPoints(int n)
{
	RoundPoints += n;
}

void Player::IncreaseTotalPoints(int n)
{
	TotalPoints += n;
}

void Player::PrintName()
{
	std::cout << name << " ";
}

int Player::GetRoundPoints()
{
	return RoundPoints;
}

int Player::GetTotalPoints()
{
	return TotalPoints;
}

void Player::ResetRoundPoints()
{
	RoundPoints = 0;
}

//Print hand to command line
void Player::DisplayHand()
{
	for (int i = 0; i < Hand.size(); i++)
	{
		Hand[i]->Print();
		std::cout << " ";
	}
	std::cout << "\n";
}

//Custom compare function for hand sorting
bool compareCardPtr(Card* a, Card* b) { return (*a < *b); }

void Player::SortHand()
{
	std::sort(Hand.begin(), Hand.end(), compareCardPtr);
	std::reverse(Hand.begin(), Hand.end());
}

//For legality of play checks, returns number of cards of given suit in hand
int Player::CheckNumSuits(int i)
{
	return Player::NumSuits[i];
}

//sets number of each suit to correct value in vector
void Player::UpdateNumSuits()
{
	for (int i = 0; i < Hand.size(); i++)
	{
		int s = Hand[i]->GetSuit();
		NumSuits[s-1] += 1;
	}
}

void Player::ReduceNumSuits(int i)
{
	NumSuits[i] -= 1;
}

void Player::PrintNumSuits()
{
	for (int i = 3; i >= 0; i--)
	{
		std::cout << NumSuits[i] << " ";
	}
	std::cout << "\n";
}

//removes card from hand and reduces appropriate suit count accordingly. Returns Pointer of played card for tracking in trick (see Table Class)
Card* Player::PlayCard(int i)
{
	int s = Hand[i]->GetSuit();
	Card* c = Hand[i];
	Hand.erase(Hand.begin()+i);
	ReduceNumSuits(s - 1);
	return c;
}