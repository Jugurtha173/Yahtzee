// Jugurtha ASMA && Hylia BOUDAHBA

#include "lancer.h"

Yahtzee::lancer::lancer()
{
	srand((unsigned int)time(nullptr));
	
	for (unsigned int i = 1; i <= numberOfDices; ++i){
		dePtr dice = std::make_shared<de>(i);
		dice->roll(numberOfFaces);
		dices.push_back(dice);
	}
}

std::vector<unsigned int> Yahtzee::lancer::getDicesOccurences() const
{
	std::vector<unsigned int> dicesvalues(numberOfFaces, 0);
	for (dePtr dice : dices) {
		++(dicesvalues.at(dice->value-1));
	}
	return dicesvalues;
}

void Yahtzee::lancer::rollAllDices()
{
	std::vector<unsigned int> indexes;
	for (unsigned int i = 1; i <= dices.size(); ++i){
		indexes.push_back(i);
	}

	rollDices(indexes);
}

void Yahtzee::lancer::rollDices(const std::vector<unsigned int>& indexes)
{
	rollDicesByIndex(indexes);
	sortDices();
	showDices();
}

void Yahtzee::lancer::rollDicesByIndex(const std::vector<unsigned int>& indexes)
{
	for (unsigned int index : indexes) {
		if (index >= 1 && index <= numberOfDices) {
			dices.at(index - 1)->roll(numberOfFaces);
		}
	}
}

void Yahtzee::lancer::sortDices() 
{
	std::sort(dices.begin(), dices.end(),
		[](const dePtr& d1, const dePtr& d2) {
			return d1->value < d2->value;
		});	
}

void Yahtzee::lancer::showDices() const
{
	std::cout
		<< "\n**********************************************\n"
		<< "resulat du jet des des : \n";

	int i = 0;
	for (dePtr dice : dices) {
		std::cout << "\t" << ++i << ":\t" << *dice << "\n";
		
	}
	std::cout << std::endl;
}
