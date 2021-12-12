#include "IA.h"


std::string Yahtzee::IA::chooseDicesToRoll() const
{
	std::string strChoices;

	for (int i = 0; i < 5; ++i) {
		unsigned int random = (unsigned int)rand() % (6 - 1 + 1) + 1;

		strChoices += std::to_string(random) + " ";
	}

	std::cout << name << " choose : " << strChoices << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	return strChoices;
}




