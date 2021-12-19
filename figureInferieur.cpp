// Jugurtha ASMA && Hylia BOUDAHBA

#include "figureInferieur.h"

unsigned int Yahtzee::chance::eval(const std::vector<unsigned int>& dicesOccurences)
{
	unsigned int sum = 0;

	for (unsigned int i = 0; i < dicesOccurences.size(); ++i) {
		sum += dicesOccurences.at(i) * i;
	}

	return sum ;	
}
