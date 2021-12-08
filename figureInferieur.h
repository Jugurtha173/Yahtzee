#pragma once

#include "figure.h"

namespace Yahtzee {
	
	class figureInferieur : public figure
	{

	public:
		figureInferieur(const std::string& name) : figure(name) {}
		~figureInferieur() {}

	};


	class full
	{



	};

	
	class chance : public figureInferieur
	{
	public:
		chance() : figureInferieur("Chance") {}

		unsigned int eval(lancer* roll) override;
	
	};

	// pour les (Brelan, Carre, Yahtzee)
	
	// size   : nombre de fois le meme des
	// points : le nombre de points que la figure rapporte (0 => la somme des des)
	template <int size, int points = 0>
	class identical : public figureInferieur {

	public:
		identical(const std::string& name) : figureInferieur(name) {}

		unsigned int eval(lancer* roll) override;
	};

	template<int size, int points>
	inline unsigned int identical<size, points>::eval(lancer* roll)
	{
		
		std::vector<unsigned int> dicesValues = roll->getDicesValues();
		int verifications = dicesValues.size() - size + 1;

		for (int i = 0; i < verifications; ++i) {
			unsigned int current = dicesValues.at(i);
			for (int j = i+1; j < size; ++j){
				if (current != dicesValues.at(j)) {
					currentPoints = 0;
					return 0;
				}
			}
		}

		unsigned int result = 0;
		if (points == 0) {
			for (unsigned int dice : dicesValues) {
				result += dice;
			}
		}
		currentPoints = result;
		return result;

	}


	// pour les suites 

	// size   : taille de la suite (Petite ou Grande)
	// points : le nombre de points que la figure rapporte
	template <int size, int points> 
	class suite : public figureInferieur {

	public:
		suite(const std::string& name) : figureInferieur(name) {}

		unsigned int eval(lancer* roll) override;
	};

	template<int size, int points>
	inline unsigned int suite<size, points>::eval(lancer* roll)
	{
		std::vector<unsigned int> dicesValues = roll->getDicesValues();
		int verifications = dicesValues.size() - size + 1;
		bool found = false;
		/*a revoir
		for (int i = 0; i < verifications; ++i) {
			for (int j = i; j < size; ++j) {
				if (dicesValues.at(j) != dicesValues.at(j+1) - 1) {
					found &= false;
				}
			}
		}

		currentPoints = 0;
		return 0;
		*/
		currentPoints = points;
		return points;
		
	}
}


