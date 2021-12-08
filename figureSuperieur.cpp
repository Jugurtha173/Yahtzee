#include "figureSuperieur.h"
#include <iomanip>


unsigned int Yahtzee::figureSuperieur::eval(lancer* roll)
{
	unsigned int sum = 0;

	for (de* dice : roll->getDices()) {
		if (*dice == value) {
			++sum;
		}
	}

	sum *= value;

	currentPoints = sum;
	return sum;
}
