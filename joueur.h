#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>


#include "lancer.h"
#include "figureSuperieur.h"
#include "figureInferieur.h"

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
		virtual ~joueur() { };

		virtual void play() const;
		void evalFigures() const;

		void makeChoice();
		unsigned int getIntInput() const;
		unsigned int getTotalPoints() const;
		bool hasFinished() const;

		std::vector<unsigned int> extractInts(std::string str) const ;

		friend std::ostream& operator<<(std::ostream& out, const joueur& player) { return out << player.name << " (" << player.getTotalPoints() << ")"; };
		friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<joueur> player) { 
			return out << player->name + " (" + std::to_string(player->getTotalPoints()) + ")";
		};
		friend class partie;
	};

}



