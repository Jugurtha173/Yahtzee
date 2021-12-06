#pragma once


#include <vector>


#include "joueur.h"
#include "lancer.h"
#include "figure.h"
#include "figuresJeu.h"

namespace Yahtzee {

	class partie
	{
		std::vector<joueur*> players;
		unsigned int numberPlayers;
		std::vector<figure*> figures;
		lancer* roll;

	public:
		partie(int numberPlayers = 2);
		~partie();

		void initPlayers();
		void launch();
		void showTable() const ;
		void separate(int allSize) const;
	};

}



