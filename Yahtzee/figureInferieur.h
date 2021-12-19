// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include "figure.h"

namespace Yahtzee {
	
	class figureInferieur : public figure
	{
	public:
		figureInferieur(const std::string& name) : figure(name) {}
		~figureInferieur() = default;
	};
	
	class chance : public figureInferieur
	{
	public:
		chance() : figureInferieur("Chance") {}
		~chance() = default;
		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};

	// pour les (Brelan, Carre, Yahtzee)
	// size   : nombre de fois le meme des
	// points : le nombre de points que la figure rapporte (0 => la somme des des)
	template <int size, int points = 0>
	class identique : public figureInferieur {

	public:
		identique(const std::string& name) : figureInferieur(name) {}
		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};

	template<int size, int points>
	inline unsigned int identique<size, points>::eval(const std::vector<unsigned int>& dicesOccurences)
	{
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
				return points;
			}
		}
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
		return result;
	}
}
