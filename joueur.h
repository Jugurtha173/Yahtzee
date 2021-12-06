#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>


#include "lancer.h"
#include "figure.h"

namespace Yahtzee {

	class joueur
	{
		//
		const static unsigned int nbrTurns = 3;

		//
		const std::string name;
		std::vector<figure*> figures;
		lancer* roll;

	public:
		joueur(std::string name,  lancer* roll, std::vector<figure*> figures);
		~joueur() { delete roll; };

		void play() const ;
		void allFiguresEval() const ;
		//void holdDices(const std::vector<unsigned int>& choices);

		void makeChoice() const ;
		unsigned int getIntInput() const ;

		bool hasFinished() const;

		std::vector<unsigned int> extractInts(std::string str) const ;

		friend std::ostream& operator<<(std::ostream& out, const joueur& player) { return out << player.name; };
		friend class partie;
	};

}



