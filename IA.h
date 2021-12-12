#pragma once
#include "joueur.h"

namespace Yahtzee {

	class IA : public joueur
	{


	public:
		IA(std::string name, std::shared_ptr<lancer> roll, std::vector<std::shared_ptr<figure>> figures)
			: joueur(name, roll, figures) {};
		~IA() {};

		std::string getChoice() const override;
	};

}

