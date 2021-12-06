#include "figure.h"
#include <iomanip>

unsigned int Yahtzee::figure::eval(lancer* roll)
{
	unsigned int sum = 0;

	for (de* dice : roll->dices) {
		if (*dice == value) {
			++sum;
		}
	}

	sum *= value;

	std::cout  << "\t" << std::setw(10) << std::left << name << " : " << sum << std::endl;
	currentValue = sum;
	return sum;
}
