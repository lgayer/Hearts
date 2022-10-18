#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Cards.h"
#include <iostream>
#include <limits>

Game::Game(std::vector<Player> players): leader(0), roundcount(0), tracker(0), HeartsBroken(false)
{
	for (int i=0; i<players.size();i++)
	{
		table.push_back(players[i]);
	}
}

Game::~Game()
{
	table.clear();
}


void Game::Deal(Deck deck)
{
	deck.Shuffle();
	for (int i=0; i<52; i++)
	{
		table[i%4].Hand.push_back(deck[i]);
	}
	for (int j = 0; j < table.size(); j++)
	{
		table[j].SortHand();
		table[j].UpdateNumSuits();
	}
}


void Game::Pass()
{
	if (roundcount % 4 == 0)
	{
		std::cout << "Pass Left" << "\n";
		std::vector<Card*>pass;
		for (int i = 0; i < table.size(); i++)
		{
			table[i].PrintName(); std::cout << "What 3 cards would you like to pass?" << "\n";
			table[i].DisplayHand();
			int a, b, c;
			for (;;)
			{
				if (std::cin >> a >> b >> c)
				{
					if (a >= 0 && a < table[i].Hand.size() && b >= 0 && b < table[i].Hand.size() && c >= 0 && c < table[i].Hand.size())
					{
						break;
					}
					else
					{
						std::cout << "Invalid integers, please enter integers corresponding to cards you wish to pass (Don't forget 0 indexing)" << "\n";
					}
				}
				else
				{
					std::cout << "Invalid Input, Please enter integer places of cards you wish to pass" << "\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			if (a > b && b > c)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (a > c && c > b)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
			}
			else if (b > a && a > c)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (b > c && c > a)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > b && b > a)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > a && a > b)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
			}
		}
		for (int i = 0; i < table.size(); i++)
		{
			int n = (i + 1) % 4;
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
		}
		for (int j = 0; j < table.size(); j++)
		{
			table[j].UpdateNumSuits();
		}
	}
	else if (roundcount % 4 == 1)
	{
		std::cout << "Pass Right" << "\n";
		std::vector<Card*>pass;
		for (int i = 0; i < table.size(); i++)
		{
			table[i].PrintName(); std::cout << "What 3 cards would you like to pass?" << "\n";
			table[i].DisplayHand();
			int a, b, c;
			for (;;)
			{
				if (std::cin >> a >> b >> c)
				{
					if (a >= 0 && a < table[i].Hand.size() && b >= 0 && b < table[i].Hand.size() && c >= 0 && c < table[i].Hand.size() && a!=b && a!=c && b!=c)
					{
						break;
					}
					else
					{
						std::cout << "Invalid integers, please enter 3 different integers corresponding to cards you wish to pass (Don't forget 0 indexing)" << "\n";
					}
				}
				else
				{
					std::cout << "Invalid Input, Please enter integer places of cards you wish to pass" << "\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			if (a > b && b > c)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (a > c && c > b)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
			}
			else if (b > a && a > c)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (b > c && c > a)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > b && b > a)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > a && a > b)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
			}
		}
		for (int i = 0; i < table.size(); i++)
		{
			int n = (i + 3) % 4;
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
		}
		for (int j = 0; j < table.size(); j++)
		{
			table[j].UpdateNumSuits();
		}
	}
	else if (roundcount % 4 == 2)
	{
		std::cout << "Pass Across" << "\n";
		std::vector<Card*>pass;
		for (int i = 0; i < table.size(); i++)
		{
			table[i].PrintName(); std::cout << "What 3 cards would you like to pass?" << "\n";
			table[i].DisplayHand();
			int a, b, c;
			for (;;)
			{
				if (std::cin >> a >> b >> c)
				{
					if (a >= 0 && a < table[i].Hand.size() && b >= 0 && b < table[i].Hand.size() && c >= 0 && c < table[i].Hand.size())
					{
						break;
					}
					else
					{
						std::cout << "Invalid integers, please enter integers corresponding to cards you wish to pass (Don't forget 0 indexing)" << "\n";
					}
				}
				else
				{
					std::cout << "Invalid Input, Please enter integer places of cards you wish to pass" << "\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			if (a > b && b > c)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (a > c && c > b)
			{
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
			}
			else if (b > a && a > c)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(c));
			}
			else if (b > c && c > a)
			{
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > b && b > a)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(b));
				pass.push_back(table[i].PlayCard(a));
			}
			else if (c > a && a > b)
			{
				pass.push_back(table[i].PlayCard(c));
				pass.push_back(table[i].PlayCard(a));
				pass.push_back(table[i].PlayCard(b));
			}
		}
		for (int i = 0; i < table.size(); i++)
		{
			int n = (i + 3) % 4;
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
			table[n].Hand.push_back(pass[0]);
			pass.erase(pass.begin());
		}
		for (int j = 0; j < table.size(); j++)
		{
			table[j].UpdateNumSuits();
		}
	}
	else if (roundcount % 4 == 3)
	{
		std::cout << "Stick Round" << "\n";
	}
}

void Game::ScoreUpdate()
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].GetRoundPoints() == 26)
		{
			for (int j = 0; j < table.size(); j++)
			{
				if (j != i)
				{
					table[j].IncreaseTotalPoints(26);
				}
			}
			table[i].ResetRoundPoints();
		}
		else
		{
			table[i].IncreaseTotalPoints(table[i].GetRoundPoints());
			table[i].ResetRoundPoints();
		}
	}
}

void Game::Trick()
{
	std::vector<Card*> trick;
	for (int i = 0; i < table.size(); i++)
	{
		table[i].PrintName(); std::cout << table[i].GetTotalPoints() << " (" << table[i].GetRoundPoints() << ") ";
	}
	std::cout << "\n";
	for (int i = 0; i < table.size(); i++)
	{
		int x = (Game::leader + i) % 4;
		table[x].DisplayHand();
		table[x].PrintName(); std::cout << "What Card Would You Like to Play?" << "\n";
		int a;
		for (;;)
		{
			if (std::cin >> a)
			{
				if (a >= 0 && a < table[i].Hand.size())
				{
					break;
				}
				else
				{
					std::cout << "Invalid integer, please enter integer corresponding to card you wish to play (Don't forget 0 indexing)" << "\n";
				}
			}
			else
			{
				std::cout << "Invalid Input, Please enter integer place of card you wish to play" << "\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		trick.push_back(table[x].PlayCard(a));
		std::cout << "Trick: ";
		for (int j = 0; j <= i; j++)
		{
			trick[j]->Print();
			std::cout << " ";
		}
		std::cout << "\n";
	}
	int adjust = leader % 4;
	leader = 0;
	for (int i = 1; i < trick.size(); i++)
	{
		if (trick[i]->GetSuit() == trick[0]->GetSuit() && *trick[leader] < *trick[i])
		{
			leader = i;
		}
	}
	leader = (leader + adjust) % 4;
	table[leader].PrintName(); std::cout << "won the trick" << "\n";
	int score = 0;
	for (Card* card : trick)
	{
		if (card->GetSuit() == Card::HEARTS)
		{
			score += 1;
		}
		else if (*card == Card(Card::QUEEN, Card::SPADES))
		{
			score += 13;
		}
	}
	table[leader].IncreaseRoundPoints(score);
	tracker += score;
}

void Game::Round()
{
	for (int i = 0; i < table.size(); i++)
	{
		table[i].PrintName(); std::cout << table[i].GetTotalPoints() << " (" << table[i].GetRoundPoints() << ") ";
	}
	std::cout << "\n";
	Pass();
	for (int i = 0; i < table.size(); i++)
	{
		for (Card* card : table[i].Hand)
		{
			if (*card == Card(Card::TWO, Card::CLUBS))
			{
				leader = i;
			}
		}
	}
	table[leader].PrintName(); std::cout << "starts the trick" << "\n";
	tracker = 0;
	while(tracker<26)
	{
		Trick();
	}
	ScoreUpdate();
	roundcount += 1;
}