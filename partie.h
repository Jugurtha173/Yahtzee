#pragma once


#include <vector>


#include "joueur.h"
#include "lancer.h"
#include "figure.h"
#include "figuresJeu.h"

namespace Yahtzee {


	class partie
	{
		static int NUMBER_OF_PLAYERS;
		static int NUMBER_OF_FACES;

		std::vector<std::shared_ptr<joueur>> players;
		unsigned int numberPlayers;
		std::vector<figure*> figures;
		std::shared_ptr<lancer> roll;

	public:

		partie(int numberPlayers = 2);
		~partie();

		void initPlayers();
		void launch();
		void showTable() const;
		void showScores();

		void separate(int allSize) const;
	};

}



