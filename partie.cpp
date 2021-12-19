// Jugurtha ASMA && Hylia BOUDAHBA

#include "partie.h"
#include <iomanip>
#include <memory>

Yahtzee::partie::partie(int numberPlayers)
{
	// verif inferieur a 2
	this->numberPlayers = (numberPlayers < 2) ? 2 : numberPlayers;

	this->roll = std::make_shared<lancer>();

	initPlayers();
}

void Yahtzee::partie::initPlayers()
{
	joueurPtr player = std::make_shared<joueur>("J #1", roll);
	addPlayer(player);

	for (unsigned int i = 2; i <= numberPlayers; ++i) {
		joueurPtr IAplayer = std::make_shared<IA>("IA #" + std::to_string(i), roll);
		addPlayer(IAplayer);

	}
}

void Yahtzee::partie::launch()
{
	std::cout << "**************** DEBUT DU JEU ****************\n\n";

	unsigned int numberFinishedPlayers = 0;

	while (numberFinishedPlayers < numberPlayers) {
		for (joueurPtr player : players) {

			std::cout 
				<< "**********************************************"<< std::endl
				<< "\tTour de : " << player->name << std::endl
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

std::vector<Yahtzee::joueurPtr> Yahtzee::partie::getPlayers() const
{
	return players;
}

Yahtzee::lancerPtr Yahtzee::partie::getLancer() const
{
	return roll;
}

void Yahtzee::partie::addPlayer(const Yahtzee::joueurPtr player)
{
	players.push_back(player);
}

void Yahtzee::partie::showTable() const
{
	size_t numberFigures = players.at(0)->figures.size();
	int sizeOfCell = 10;
	int sizeOfRow = sizeOfCell + (2 * sizeOfCell * numberPlayers);

	separate(sizeOfRow);

	std::cout << std::setw(sizeOfCell) << "Yahtzee" << std::setw(sizeOfCell) << "|";
	for (joueurPtr player : players) {
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

	std::cout << std::setw(sizeOfCell) << "TOTAL" << std::setw(sizeOfCell) << "|";
	for (joueurPtr player : players) {
		std::cout << std::setw(sizeOfCell) << player->getTotalPoints() << std::setw(sizeOfCell) << "|";
	}

	separate(sizeOfRow);
	std::cout << "\n\n";
}

void Yahtzee::partie::showScores()
{
	std::sort(players.begin(), players.end(),
		[](const joueurPtr& p1, const joueurPtr& p2) {
			return p1->getTotalPoints() > p2->getTotalPoints();
		}
	);
	
	int size = 12;
	
	for (unsigned int i = 0; i < players.size(); ++i) {

		for (unsigned int j = 0; j < i; ++j) {
			std::cout << std::setw(size) << "|";
		}

		std::cout << "|  " << std::setw(size) << players.at(i)->name << "\n";


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
