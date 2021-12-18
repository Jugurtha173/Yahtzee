#pragma once


#include <vector>


#include "joueur.h"
#include "IA.h"
#include "lancer.h"
#include "figure.h"
#include "figuresJeu.h"

namespace Yahtzee {


	class partie
	{
		static int NUMBER_OF_PLAYERS;
		static int NUMBER_OF_FACES;

		std::vector<joueurPtr> players;
		unsigned int numberPlayers;
		std::vector<figure*> figures;
		lancerPtr roll;

	public:

		partie(int numberPlayers = 2);
		~partie() = default;

		void initPlayers();
		void launch();
		void showTable() const;
		void showScores();

		void separate(int allSize) const;
	};

}



