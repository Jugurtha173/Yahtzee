#include "figureInferieur.h"



unsigned int Yahtzee::chance::eval(std::vector<unsigned int>& dicesOccurences)
{
	unsigned int sum = 0;

	for (unsigned int i = 1; i <= dicesOccurences.size(); ++i) {
		sum += dicesOccurences.at(i-1) * i;
	}

	currentPoints = sum;
	return sum ;

	
}
