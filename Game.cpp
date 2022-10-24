#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Cards.h"
#include <iostream>
#include <limits>

//constructor takes in vector of players and copies to vector table
Game::Game(std::vector<Player> players): leader(0), roundcount(0), tracker(0), bust(false), HeartsBroken(false)
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

//bool to determine when game is over
bool Game::CheckBust()
{
	return bust;
}

//deals input deck to players at table, currently presumes 4 players, updates numsuits for each player once hand dealt
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

//pass function, determines if its pass left, right, across or stick based on roundcount
//to ensure correct pass, currently orders 3 input integers from high to low before removing the 3 cards from hand
//once pass completed, updates numsuits for legalit checks on plays
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
					if (a >= 0 && a < table[i].Hand.size() && b >= 0 && b < table[i].Hand.size() && c >= 0 && c < table[i].Hand.size() && a != b && a != c && b != c)
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
					if (a >= 0 && a < table[i].Hand.size() && b >= 0 && b < table[i].Hand.size() && c >= 0 && c < table[i].Hand.size() && a!=b && a!=c && b!=c)
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
			int n = (i + 2) % 4;
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

// updates players total scores at end of a round
// shooting is accounted for and player given choice whether to reduce or increase opponents
// House rule reducing also accounted for (hitting 100 exactly reduces to 50)
// once this is done, checks if game is over, does another round on ties.
void Game::ScoreUpdate()
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].GetRoundPoints() == 26)
		{
			std::cout << "Scores are: ";
			for (int j = 0; j < table.size(); j++)
			{
				table[j].PrintName(); std::cout << table[j].GetTotalPoints() << " ";
			}
			std::cout << "\n";
			table[i].PrintName(); std::cout << "shot! Enter 0 to increase other players score by 26, type 1 to reduce your score by 26" << "\n";
			
			int shoot;
			for (;;)
			{
				if (std::cin >> shoot)
				{
					if (shoot == 0)
					{
						for (int j = 0; j < table.size(); j++)
						{
							if (j != i)
							{
								table[j].IncreaseTotalPoints(26);
							}
						}
						table[i].ResetRoundPoints();
						break;
					}
					else if (shoot == 1)
					{
						table[i].IncreaseTotalPoints(-26);
						table[i].ResetRoundPoints();
						break;
					}
					else
					{
						std::cout << "Invalid integer, please enter  0 to increase other players score by 26, or enter 1 to reduce your score by 26" << "\n";
					}
				}
				else
				{
					std::cout << "Invalid Input, Please enter  0 to increase other players score by 26, or enter 1 to reduce your score by 26" << "\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}
		else
		{
			table[i].IncreaseTotalPoints(table[i].GetRoundPoints());
			table[i].ResetRoundPoints();
		}
	}
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].GetTotalPoints() == 100)
		{
			table[i].IncreaseRoundPoints(-50);
		}
	}
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].GetTotalPoints() > 100)
		{
			bool tie = false;
			int winner = -1;
			int winningscore = table[i].GetTotalPoints();
			for (int j = 0; j < table.size(); j++)
			{
				if (table[j].GetTotalPoints() < table[i].GetTotalPoints() && table[j].GetTotalPoints() < winningscore)
				{
					winner = j;
					winningscore = table[j].GetTotalPoints();
				}
				else if (table[j].GetTotalPoints() == winningscore)
				{
					tie = true;
					std::cout << "Tie Game; Another Round" << "\n";
				}

			}
			if (tie == false);
			{
				table[winner].PrintName(); std::cout << "Wins!";
				bust = true;
			}
		}
	}
}

//separate function for first trick to ensure 2 of clubs is lead and no points cards are played (unless someone has all points cards in hand)
void Game::FirstTrick()
{
	std::vector<Card*> trick;
	for (int i = 0; i < table.size(); i++)
	{
		table[i].PrintName(); std::cout << table[i].GetTotalPoints() << " (" << table[i].GetRoundPoints() << ") ";
	}
	std::cout << "\n";
	table[leader].DisplayHand();
	table[leader].PrintName(); std::cout << "What Card Would You Like to Play?" << "\n";
	int b;
	for (;;)
	{
		if (std::cin >> b)
		{
			if (b >= 0 && b < table[leader].Hand.size())
			{
				if (*table[leader].Hand[b] == Card(Card::TWO,Card::CLUBS))
				{
					break;
				}
				else
				{
					std::cout << "Invalid choice, Please lead the 2C" << "\n";
				}
			}
			else
			{
				std::cout << "Invalid choice, please enter integer corresponding to card you wish to play (Don't forget 0 indexing)" << "\n";
			}
		}
		else
		{
			std::cout << "Invalid Input, Please enter integer place of card you wish to play" << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	trick.push_back(table[leader].PlayCard(b));
	std::cout << "Trick: "; trick[0]->Print();  std::cout << "\n";

	for (int i = 1; i < table.size(); i++)
	{
		int x = (leader + i) % 4;
		table[x].DisplayHand();
		table[x].PrintName(); std::cout << "What Card Would You Like to Play?" << "\n";
		int a;
		for (;;)
		{
			if (std::cin >> a)
			{
				if (a >= 0 && a < table[x].Hand.size())
				{
					if (table[x].Hand[a]->GetSuit() == trick[0]->GetSuit())
					{
						break;
					}
					else
					{
						if (table[x].CheckNumSuits(trick[0]->GetSuit() - 1) == 0)
						{
							if (table[x].Hand[a]->GetSuit() == Card::HEARTS)
							{
								if (table[x].CheckNumSuits(Card::HEARTS) == 13)
								{
									break;
								}
								else 
								{
									std::cout << "Invalid choice, No points cards in Round 1" << "\n";
								}
							}
							else if (*table[x].Hand[a] == Card(Card::QUEEN, Card::SPADES))
							{
								if (table[x].CheckNumSuits(Card::HEARTS) == 12)
								{
									std::cout << "Invalid choice, No points cards in Round 1" << "\n";
								}
								else
								{
									std::cout << "Invalid choice, No points cards in Round 1" << "\n";
								}
							}
							else
							{
								break;
							}
						}
						else
						{
							std::cout << "Invalid choice, Please follow suit" << "\n";
						}
					}
				}
				else
				{
					std::cout << "Invalid choice, please enter integer corresponding to card you wish to play (Don't forget 0 indexing)" << "\n";
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
	int adjust = leader;
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
			HeartsBroken = true;
		}
		else if (*card == Card(Card::QUEEN, Card::SPADES))
		{
			score += 13;
		}
	}
	table[leader].IncreaseRoundPoints(score);
	tracker += score;
}


// function to do a trick, determines winner of round and assigns round points according to what was played
void Game::Trick()
{
	std::vector<Card*> trick;
	for (int i = 0; i < table.size(); i++)
	{
		table[i].PrintName(); std::cout << table[i].GetTotalPoints() << " (" << table[i].GetRoundPoints() << ") ";
	}
	std::cout << "\n";
	table[leader].DisplayHand();
	table[leader].PrintName(); std::cout << "What Card Would You Like to Play?" << "\n";
	int b;
	for (;;)
	{
		if (std::cin >> b)
		{
			if (b >= 0 && b < table[leader].Hand.size())
			{
				if (table[leader].Hand[b]->GetSuit() == Card::HEARTS)
				{
					if (HeartsBroken == true)
					{
						break;
					}
					else
					{
						if (table[leader].CheckNumSuits(Card::HEARTS - 1) == table[leader].Hand.size())

						{
							break;
						}
						else
						{
							std::cout << "Hearts not Broken, Please pick another card to lead" << "\n";
						}
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				std::cout << "Invalid choice, please enter integer corresponding to card you wish to play (Don't forget 0 indexing)" << "\n";
			}
		}
		else
		{
			std::cout << "Invalid Input, Please enter integer place of card you wish to play" << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	trick.push_back(table[leader].PlayCard(b));
	std::cout << "Trick: "; trick[0]->Print();  std::cout << "\n";

	for (int i = 1; i < table.size(); i++)
	{
		int x = (leader + i) % 4;
		table[x].DisplayHand();
		table[x].PrintName(); std::cout << "What Card Would You Like to Play?" << "\n";
		int a;
		for (;;)
		{
			if (std::cin >> a)
			{
				if (a >= 0 && a < table[x].Hand.size())
				{
					if (table[x].Hand[a]->GetSuit() == trick[0]->GetSuit())
					{
						break;
					}
					else
					{
						if (table[x].CheckNumSuits(trick[0]->GetSuit() - 1) == 0)
						{
							break;
						}
						else
						{
							std::cout << "Invalid choice, Please follow suit" << "\n";
						}
					}
				}
				else
				{
					std::cout << "Invalid choice, please enter integer corresponding to card you wish to play (Don't forget 0 indexing)" << "\n";
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
	int adjust = leader;
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
			HeartsBroken = true;
		}
		else if (*card == Card(Card::QUEEN, Card::SPADES))
		{
			score += 13;
		}
	}
	table[leader].IncreaseRoundPoints(score);
	tracker += score;
}

// plays a full hand, determining leader by who has 2 of clubs, ending once all point cards have been played
void Game::Round()
{
	HeartsBroken = false;
	for (int i = 0; i < table.size(); i++)
	{
		table[i].PrintName(); std::cout << table[i].GetTotalPoints() << "(" << table[i].GetRoundPoints() << ") ";
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
	FirstTrick();
	while(tracker<26)
	{
		Trick();
	}
	ScoreUpdate();
	roundcount += 1;
}