#include "lancer.h"



Yahtzee::lancer::lancer()
{
	int numberDices = 5;
	srand(time(nullptr)); // Seed the time
	

	for (int i = 1; i <= numberDices; ++i){
		dices.push_back(new de(i));
	}
}

Yahtzee::lancer::~lancer()
{
}

std::vector<unsigned int> Yahtzee::lancer::getDicesValues() const
{
	std::vector<unsigned int> dicesvalues;
	for (de* dice : dices) {
		dicesvalues.push_back(dice->value);
	}
	return dicesvalues;
}

void Yahtzee::lancer::rollDices()
{

	int min = 1;
	int max = 6;
	
	std::cout << "resulat du jet des des : \n";

	for (de* dice : dices) {
		if (!dice->isHeld) {
			unsigned int random = (unsigned int)rand() % (max - min + 1) + 1; // Generate the number, assign to variable.
			dice->value = random;
		}
	}
	sortDices();
	showDices();
	
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
		if (index >= 1 && index <= 5) {
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

