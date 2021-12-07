#pragma once


#include <vector>
#include "figure.h"
#include "figureSuperieur.h"

namespace Yahtzee {

	class figuresJeu
	{

	public:

		static std::vector<figure*> getFigures() {
			std::vector<figure*> figures;

			figures.push_back(new figureSuperieur("As", 1));
			figures.push_back(new figureSuperieur("Deux", 2));
			figures.push_back(new figureSuperieur("Trois", 3));
			figures.push_back(new figureSuperieur("Quatre", 4));
			figures.push_back(new figureSuperieur("Cinq", 5));
			figures.push_back(new figureSuperieur("Six", 6));

			

			/*
			
			
			figures.push_back(new figure("As", 1));
			figures.push_back(new figure("Deux", 2));
			figures.push_back(new figure("Trois", 3));
			figures.push_back(new figure("Quatre", 4));
			figures.push_back(new figure("Cinq", 5));
			figures.push_back(new figure("Six", 6));

			*/

			return figures;
		}
	};

}



