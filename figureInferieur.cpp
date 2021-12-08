#include "figureInferieur.h"



unsigned int Yahtzee::chance::eval(lancer* roll)
{
	unsigned int sum = 0;

	std::vector<unsigned int> dicesValues = roll->getDicesValues();
	for (unsigned int dice : dicesValues) {
		sum += dice;
	}

	currentPoints = sum;
	return sum ;

	
}
