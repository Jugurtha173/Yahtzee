#pragma once

#include "figure.h"

namespace Yahtzee {

	class figureSuperieur : public figure
	{

	public:
		figureSuperieur(const std::string& name, unsigned int value) : figure(name, value) {};
		~figureSuperieur() {};
		unsigned int eval(lancer* roll) override;

	};


}


