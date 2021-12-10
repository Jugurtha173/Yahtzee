#include "de.h"

void Yahtzee::de::roll(int max, int min)
{
	unsigned int random = (unsigned int)rand() % (max - min + 1) + 1;
	value = random;
}

