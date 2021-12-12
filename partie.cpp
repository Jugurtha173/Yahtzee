#include "partie.h"
#include <iomanip>
#include <memory>

Yahtzee::partie::partie(int numberPlayers)
{
	// verif inferieur a 2
	this->numberPlayers = (numberPlayers < 2) ?  2 : numberPlayers;

	this->roll = std::make_shared<lancer>();

	initPlayers();
}

Yahtzee::partie::~partie()
{
}

void Yahtzee::partie::initPlayers()
{
	for (unsigned int i = 1; i <= numberPlayers; ++i) {
		// to delete
		std::shared_ptr<joueur> player = std::make_shared<joueur>("J #" + std::to_string(i), roll, figuresJeu::getFigures());
		//joueur* player = new joueur("Joueur #" + std::to_string(i), roll, figuresJeu::getFigures());
		players.push_back(player);

	}
}

void Yahtzee::partie::launch()
{
	std::cout << "**************** DEBUT DU JEU ****************\n\n";

	unsigned int numberFinishedPlayers = 0;

	while (numberFinishedPlayers < numberPlayers) {
		for (std::shared_ptr<joueur> player : players) {

			std::cout 
				<< "**********************************************"<< std::endl
				<< "\tTour de : " << *player << std::endl
				<< "**********************************************"<< std::endl;

			player->play();
			player->makeChoice();
			showTable();
			if (player->hasFinished()) {
				numberFinishedPlayers++;
			}

		}
	}
	
	showScores();

}

void Yahtzee::partie::showTable() const
{

	unsigned int numberFigures = players.at(0)->figures.size();
	int sizeOfCell = 10;
	int sizeOfRow = sizeOfCell + (2 * sizeOfCell * numberPlayers);

	separate(sizeOfRow);
	

	std::cout << std::setw(sizeOfCell) << "Yahtzee" << std::setw(sizeOfCell) << "|";
	for (std::shared_ptr<joueur> player : players) {
		std::cout << std::setw(sizeOfCell) << player << std::setw(sizeOfCell) << "|";
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

void Yahtzee::partie::showScores()
{

	std::sort(players.begin(), players.end(),
		[](const std::shared_ptr<joueur>& p1, const std::shared_ptr<joueur>& p2) {
			return p1->getTotalPoints() > p2->getTotalPoints();
		}
	);
	
	int size = 12;
	
	for (unsigned int i = 0; i < players.size(); ++i) {

		for (unsigned int j = 0; j < i; ++j) {
			std::cout << std::setw(size) << "|";
		}

		std::cout << "|  " << std::setw(size) << players.at(i) << "\n";


		for (unsigned int j = 0; j < i; ++j) {
			std::cout << std::setw(size) << "|";
		}
		std::cout << "|-----------|\n";
		
	}

	for (unsigned int i = 0; i < players.size(); ++i) {
		std::cout << "------------";

	}
	std::cout << "|";

	
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
