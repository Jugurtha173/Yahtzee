// Jugurtha ASMA && Hylia BOUDAHBA

#pragma once
#include "figure.h"

namespace Yahtzee {

	class figureSuperieur : public figure
	{
		unsigned int value;

	public:
		figureSuperieur(const std::string& name, unsigned int value) : figure(name), value(value) {};
		~figureSuperieur() = default;
		unsigned int eval(const std::vector<unsigned int>& dicesOccurences) override;
	};
}
