// Jugurtha ASMA && Hylia BOUDAHBA

#include "de.h"

void Yahtzee::de::roll(int max, int min)
{
	unsigned int random = (unsigned int)rand() % (max - min + 1) + 1;
	value = random;
}

std::ostream& Yahtzee::operator<<(std::ostream& out, const de& dice)
{
	return out << "[" << dice.value << "] ";
}
