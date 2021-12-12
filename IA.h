#pragma once
#include "joueur.h"
#include "figure.h"

#include <thread>
#include <chrono>

namespace Yahtzee {

	class IA : public joueur
	{


	public:
		IA(std::string name, std::shared_ptr<lancer> roll, std::vector<std::shared_ptr<figure>> figures)
			: joueur(name, roll, figures) {};
		~IA() {};

		std::string chooseDicesToRoll() const override;


		std::shared_ptr<figure> chooseFigure() const override {

			std::shared_ptr<figure> choosenFigure = figures.at(0);
			for (std::shared_ptr<figure> figure : figures) {
				if (!figure->isUsed()) {
					if (*choosenFigure <= *figure) {
						choosenFigure = figure;
					}
				}
			}

			std::cout << name << " a choisie : " << choosenFigure->getName() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return choosenFigure;

			/*
			// IA sans queue ni tete
			unsigned int random = (unsigned int)rand() % (figures.size());
			std::shared_ptr<figure> choosenFigure = figures.at(random);

			if (!(choosenFigure->isUsed())) {
				std::cout << name << " choose : " << choosenFigure->getName() << std::endl;
				return choosenFigure;
			}
			else {
				return chooseFigure();
			}
			*/
		};
	};

}

