#pragma once

#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#include <vector>


class Game
{
	public:
		int leader, tracker, roundcount;
		bool HeartsBroken;
		std::vector <Player> table;


		Game(std::vector <Player> players);
		~Game();

		void Deal(Deck deck);
		void Trick();
		void Pass();
		void Round();
		void ScoreUpdate();


};