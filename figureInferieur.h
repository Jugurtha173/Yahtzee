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

		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	
	};

	// pour les (Brelan, Carre, Yahtzee)
	
	// size   : nombre de fois le meme des
	// points : le nombre de points que la figure rapporte (0 => la somme des des)
	template <int size, int points = 0>
	class identical : public figureInferieur {

	public:
		identical(const std::string& name) : figureInferieur(name) {}

		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};

	template<int size, int points>
	inline unsigned int identical<size, points>::eval(const std::vector<unsigned int>& dicesOccurences)
	{
		/*
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
		*/


		bool found = false;
		unsigned int result = 0;
		for (unsigned int dice = 1; dice <= dicesOccurences.size(); ++dice ) {
			unsigned int occurenceDice = dicesOccurences.at(dice-1);
			if (occurenceDice == size) {
				found = true;
			}
			result += (occurenceDice * dice);
		}

		
		result = found ? ( points > 0 ? points : result) : 0	; 
		

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

		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};

	template<int size, int points>
	inline unsigned int suite<size, points>::eval(const std::vector<unsigned int>& dicesOccurences)
	{
		
		int straightLenght = 0;
		for (unsigned int diceOccurence : dicesOccurences) {

			if (diceOccurence > 0) {
				straightLenght++;
			}
			else {
				straightLenght = 0; // reboot
			}

			if (straightLenght == size) {
				currentPoints = points;
				return points;
			}
		}

		currentPoints = 0;
		return 0;
		
	}

	// pour plusieurs figures en meme temps
	// FirstSize   : taille de la premiere figure
	// FirstSize   : taille de la deuxieme figure
	// points	   : le nombre de points que la figure rapporte
	template <int FirstSize, int secondSize, int points>
	class figuresMultiple : public figureInferieur {

	public:
		figuresMultiple(const std::string& name) : figureInferieur(name) {}

		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};

	
	template<int FirstSize, int secondSize, int points>
	inline unsigned int figuresMultiple<FirstSize, secondSize, points>::eval(const std::vector<unsigned int>& dicesOccurences)
	{
		bool found1 = false;
		bool found2 = false;
		unsigned int result = 0;
		for (unsigned int dice = 1; dice <= dicesOccurences.size(); ++dice) {
			unsigned int occurenceDice = dicesOccurences.at(dice - 1);
			result += (occurenceDice * dice);
			if (occurenceDice == FirstSize ) {
				found1 = true;
			}
			if ( occurenceDice == secondSize) {
				found2 = true;
			}

		}


		result = (found1 && found2) ? (points > 0 ? points : result) : 0;


		currentPoints = result;
		return result;


	}

}


