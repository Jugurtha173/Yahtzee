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

		void play() const;
		void evalFigures() const;
		const std::vector<std::shared_ptr<figure>> getUnusedFigures() const;

		virtual std::string chooseDicesToRoll() const;
		virtual std::shared_ptr<figure> chooseFigure() const {

			std::string strChoice;
			std::getline(std::cin, strChoice);

			for (std::shared_ptr<figure> figure : figures) {
				if (figure->name.find(strChoice) != std::string::npos) {
					if (!figure->isUsed()) {
						return figure;
					}
					else {
						std::cout << "Choisir une figure diponible : ";
						return chooseFigure();
					}
				}
			}

			std::cout << "Choisir une figure existante : ";
			return chooseFigure();


				/*
				unsigned int input;

				try {

					input = extractInts(strChoice).at(0);
				}
				catch (std::exception e) {
					std::cout << "\nSaisir une valeur entiere (indice) : ";
					return chooseFigure();
				}

				if (input < 1 || input > figures.size() || figures.at(input-1)->isUsed()) {

					std::cout << "\nSaisir l'indice des figures diponibles :  ";
					return chooseFigure();

				}
				*/
				//return input;
			
		}

		void makeChoice();
		
		unsigned int getTotalPoints() const;
		bool hasFinished() const;

		std::vector<unsigned int> extractInts(std::string str) const ;

		friend std::ostream& operator<<(std::ostream& out, const joueur& player);
		friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<joueur> player);

		friend class partie;
	};

	std::ostream& operator<<(std::ostream& out, const joueur& player);
	std::ostream& operator<<(std::ostream& out, const std::shared_ptr<joueur> player);

}



