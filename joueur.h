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
		unsigned int totalSup = 0;
		unsigned int totalInf = 0;
		const std::string name;
		std::vector<std::shared_ptr<figure>> figures;
		std::shared_ptr<lancer> roll;

	public:
		joueur(std::string name,  std::shared_ptr<lancer> roll, std::vector<std::shared_ptr<figure>> figures);
		~joueur() { };

		void play() const ;
		void evalFigures() const ;

		void makeChoice() const ;
		unsigned int getIntInput() const ;

		bool hasFinished() const;

		std::vector<unsigned int> extractInts(std::string str) const ;

		friend std::ostream& operator<<(std::ostream& out, const joueur& player) { return out << player.name; };
		friend class partie;
	};

}



