#pragma once


#include <vector>
#include "figureSuperieur.h"
#include "figureInferieur.h"

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

			
			figures.push_back(new identical<3>("Brelan"));
			figures.push_back(new suite<4, 30>("Petite S"));
			figures.push_back(new suite<5, 40>("Grande S"));
			figures.push_back(new figuresMultiple<3, 2, 25>("Full"));
			figures.push_back(new identical<4>("Carre"));
			figures.push_back(new identical<5, 50>("Yahtzee"));
			figures.push_back(new chance());

			return figures;
		}
	};

}



