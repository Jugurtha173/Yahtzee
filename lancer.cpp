#include "lancer.h"



Yahtzee::lancer::lancer()
{
	srand(time(nullptr)); // Seed the time
	

	for (int i = 1; i <= 5; ++i){
		dices.push_back(new de(i));
	}
}

Yahtzee::lancer::~lancer()
{
}

void Yahtzee::lancer::rollDices()
{
	std::cout << "resulat du jet des des : \n";

	for (de* dice : dices) {
		if (!dice->isHeld) {
			unsigned int random = (unsigned int)rand() % (6 - 1 + 1) + 1; // Generate the number, assign to variable.
			dice->value = random;
		}
	}
	showDices();
	
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

