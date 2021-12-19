// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include "joueur.h"
#include "figure.h"
#include <thread>
#include <chrono>

namespace Yahtzee {

	class IA : public joueur
	{
	public:
		IA(std::string name, lancerPtr roll) : joueur(name, roll) {};
		~IA() = default;

		std::string chooseDicesToRoll() const override;
		figurePtr chooseFigure() const override;
	};
}
