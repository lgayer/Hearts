#pragma once

#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include <vector>


class Game
{
	public:
// leader tracks who starts a hand, tracker determines when all point cards have been played, roundcount determines which pass
		int leader, tracker, roundcount;
// HeartsBroken is for legality checks in tricks, bust determines when the game ends
		bool HeartsBroken, bust;
		std::vector <Player> table;


		Game(std::vector <Player> players);
		~Game();
		bool CheckBust();
		void Deal(Deck deck);
		void FirstTrick();
		void Trick();
		void Pass();
		void Round();
		void ScoreUpdate();


};