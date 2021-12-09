#include "figureSuperieur.h"
#include <iomanip>


unsigned int Yahtzee::figureSuperieur::eval(std::vector<unsigned int>& dicesOccurences)
{

	unsigned int sum = dicesOccurences.at(value-1);

	/*
	for (de* dice : dices) {
		if (*dice == value) {
			++sum;
		}
	}
	*/
	sum *= value;

	currentPoints = sum;
	return sum;
}
