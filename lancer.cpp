#include "lancer.h"



Yahtzee::lancer::lancer()
{
	srand((unsigned int)time(nullptr)); // Seed the time
	

	for (unsigned int i = 1; i <= numberOfDices; ++i){
		dices.push_back(new de(i));
	}
}

Yahtzee::lancer::~lancer()
{
}

std::vector<unsigned int> Yahtzee::lancer::getDicesOccurences() const
{
	std::vector<unsigned int> dicesvalues(numberOfFaces, 0);
	for (de* dice : dices) {
		++(dicesvalues.at(dice->value-1));
	}
	return dicesvalues;
}

std::vector<unsigned int> Yahtzee::lancer::rollDices()
{

	int min = 1;
	
	std::cout << "\nresulat du jet des des : \n";

	for (de* dice : dices) {
		if (!dice->isHeld) {
			unsigned int random = (unsigned int)rand() % (numberOfFaces - min + 1) + 1; // Generate the number, assign to variable.
			dice->value = random;
		}
	}
	sortDices();
	showDices();
	return getDicesOccurences();
	
}

void Yahtzee::lancer::sortDices() 
{
	//std::sort((&dices)->begin(), (&dices)->end());



	
	std::sort(dices.begin(), dices.end(),
		[]( de* d1, de* d2) {
			return d1->value < d2->value;
		});
		
}

void Yahtzee::lancer::holdDicesByIndex(const std::vector<unsigned int>& indexes, bool hold)
{

	for (de* dice : dices) {
		dice->isHeld = false;
	}

	for (unsigned int index : indexes) {
		if (index >= 1 && index <= numberOfDices) {
			dices.at(index-1)->isHeld = true;
		}
	}

}

void Yahtzee::lancer::unholdDicesByIndex(const std::vector<unsigned int>& indexes)
{
	holdDicesByIndex(indexes, false);
}

void Yahtzee::lancer::unholdAll()
{
	for (de* dice : dices) {
		dice->isHeld = false;
	}
}

void Yahtzee::lancer::showDices() const
{
	int i = 0;
	for (de* dice : dices) {
		std::cout << "\t" << ++i << ":\t" << *dice << "\n";
		
	}
	std::cout << std::endl;
}

