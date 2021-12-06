#include "partie.h"
#include <iomanip>

Yahtzee::partie::partie(int numberPlayers)
{
	// verif inferieur a 2
	this->numberPlayers = numberPlayers;

	// lancer to delete
	this->roll = new lancer();

	initPlayers();
}

Yahtzee::partie::~partie()
{
}

void Yahtzee::partie::initPlayers()
{
	for (unsigned int i = 1; i <= numberPlayers; ++i) {
		// to delete
		joueur* player = new joueur("Joueur #" + std::to_string(i), roll, figuresJeu::getFigures());
		players.push_back(player);

	}
}

void Yahtzee::partie::launch()
{
	std::cout << "**************** STARTING GAME ****************\n\n";

	unsigned int numberFinishedPlayers = 0;

	while (numberFinishedPlayers < numberPlayers) {
		for (joueur* player : players) {

			std::cout << "Tour de : " << *player << std::endl;

			player->play();
			roll->unholdAll();
			showTable();

		}
	}
	

}

void Yahtzee::partie::showTable() const
{

	unsigned int numberFigures = players.at(0)->figures.size();
	int sizeOfCell = 10;
	int sizeOfRow = sizeOfCell + (2 * sizeOfCell * numberPlayers);

	separate(sizeOfRow);
	

	std::cout << std::setw(sizeOfCell) << "Yahtzee" << std::setw(sizeOfCell) << "|";
	for (joueur* player : players) {
		std::cout << std::setw(sizeOfCell) << player->name << std::setw(sizeOfCell) << "|";
	}
	separate(sizeOfRow);

	for (unsigned int i = 0; i < numberFigures; ++i) {

		for (unsigned int j = 0; j < numberPlayers; ++j) {
			auto fig = players.at(j)->figures.at(i);
			if (j == 0) std::cout << std::setw(sizeOfCell) << fig->name << std::setw(sizeOfCell) << "|";

			std::cout << std::setw(sizeOfCell) << *(fig) << std::setw(sizeOfCell) << "|";

		}

		separate(sizeOfRow);
	}

	std::cout << "\n";
}

void Yahtzee::partie::separate(int sizeOfRow) const
{
	std::cout 
		<< std::endl
		<< std::setfill('_')
		<< std::setw(sizeOfRow) 
		<< "" 
		<< std::endl 
		<< std::setfill(' ');

}