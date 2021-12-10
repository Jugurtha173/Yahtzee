#include "figureSuperieur.h"
#include <iomanip>


unsigned int Yahtzee::figureSuperieur::eval(const std::vector<unsigned int>& dicesOccurences)
{

	unsigned int sum = dicesOccurences.at(value-1);

	sum *= value;

	currentPoints = sum;
	return sum;
}
