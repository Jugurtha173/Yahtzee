// Jugurtha ASMA && Hylia BOUDAHBA

#include "IA.h"

std::string Yahtzee::IA::chooseDicesToRoll() const
{
	std::string strChoices;

	for (int i = 0; i < 5; ++i) {
		unsigned int random = (unsigned int)rand() % (6 - 1 + 1) + 1;

		strChoices += std::to_string(random) + " ";
	}

	std::cout << name << " choose : " << strChoices << std::endl;

	//std::this_thread::sleep_for(std::chrono::seconds(1));

	return strChoices;
}

Yahtzee::figurePtr Yahtzee::IA::chooseFigure() const
{
	// choisie le maximum de points
	figurePtr choosenFigure = nullptr;// = figures.at(0);
	for (figurePtr figure : figures) {
		if (!figure->isUsed()) {
			if ( (choosenFigure == nullptr) || (*choosenFigure <= *figure) ) {
				choosenFigure = figure;
			}
		}
	}

	std::cout << name << " a choisie : " << choosenFigure->getName() << std::endl;
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	return choosenFigure;
}




