// Jugurtha ASMA && Hylia BOUDAHBA

#include "figureSuperieur.h"

unsigned int Yahtzee::figureSuperieur::eval(const std::vector<unsigned int>& dicesOccurences)
{
	unsigned int sum = dicesOccurences.at(value-1);

	sum *= value;
	return sum;
}
