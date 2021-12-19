// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include <vector>
#include "figureSuperieur.h"
#include "figureInferieur.h"

namespace Yahtzee {

	class figuresJeu
	{

	public:

		static std::vector<figurePtr> getFigures() {

			std::vector<figurePtr> figures;

			figures.push_back(std::make_shared<figureSuperieur>("As", 1));
			figures.push_back(std::make_shared<figureSuperieur>("Deux", 2));
			figures.push_back(std::make_shared<figureSuperieur>("Trois", 3));
			figures.push_back(std::make_shared<figureSuperieur>("Quatre", 4));
			figures.push_back(std::make_shared<figureSuperieur>("Cinq", 5));
			figures.push_back(std::make_shared<figureSuperieur>("Six", 6));
			
			figures.push_back(std::make_shared<identique<3>>("Brelan"));
			figures.push_back(std::make_shared<suite<4, 30>>("Petite S"));
			figures.push_back(std::make_shared<suite<5, 40>>("Grande S"));
			figures.push_back(std::make_shared<figuresMultiple<3, 2, 25>>("Full"));
			figures.push_back(std::make_shared<identique<4>>("Carre"));
			figures.push_back(std::make_shared<identique<5, 50>>("Yahtzee"));
			figures.push_back(std::make_shared<chance>());
			
			return figures;
		}
	};
}
