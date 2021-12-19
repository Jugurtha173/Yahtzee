// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "lancer.h"
#include "figure.h"
#include "figureSuperieur.h"
#include "figureInferieur.h"

namespace Yahtzee {

	class joueur
	{
	protected:
		
		const static unsigned int nbrTurns = 3;
		
		unsigned int totalSup = 0;
		unsigned int totalInf = 0;
		const std::string name;
		std::vector<figurePtr> figures;
		lancerPtr roll;

	public:
		joueur(std::string name, lancerPtr roll);
		virtual ~joueur() = default;

		void play() const;
		void evalFigures() const;

		virtual std::string chooseDicesToRoll() const;
		virtual figurePtr chooseFigure() const;

		void makeChoice();
		
		unsigned int getTotalPoints() const;
		std::string getName() const;
		std::vector<figurePtr> getFigures() const;
		bool hasFinished() const;

		std::vector<unsigned int> extractInts(std::string str) const ;

		friend std::ostream& operator<<(std::ostream& out, const joueur& player);

		friend class partie;
	};

	std::ostream& operator<<(std::ostream& out, const joueur& player);

	typedef std::shared_ptr<joueur> joueurPtr;
}
