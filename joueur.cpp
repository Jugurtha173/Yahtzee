#include "joueur.h"
#include <iomanip>

Yahtzee::joueur::joueur(std::string name, std::shared_ptr<lancer> roll, std::vector<std::shared_ptr<figure>> figures) :
    name(name), roll(roll), figures(figures)
{

};

void Yahtzee::joueur::play() const 
{
    roll->rollAllDices();
	std::string strChoices;
	for ( unsigned int i = 1; i <= nbrTurns; ++i) {


        // evaluation des figures
        evalFigures();

        if (i < nbrTurns) {
            // hold
            std::cout 
                << "\n**********************************************\n"
                << "Selectionez les indices des des a RELANCER\n" <<
                "(ex. 1 3 5) | (Entrer pour faire un choix): ";

            strChoices = getChoice(); // std::getline(std::cin, strChoices);
            if (strChoices.empty()) break;
            std::vector<unsigned int> indexes = extractInts(strChoices);
            roll->rollDices(indexes);
        }
	}
}

std::string Yahtzee::joueur::getChoice() const
{
    std::string strChoices;
    std::getline(std::cin, strChoices);
    return strChoices;
}

void Yahtzee::joueur::evalFigures() const
{

    // lancer les des
    std::vector<unsigned int> dicesOccurences = roll->getDicesOccurences();

    std::cout << "Ce que vous pouvez avoir : \n";
    int index = 0;
    for (std::shared_ptr<figure> figure : figures) {
        ++index;
        if (!figure->isUsed()) {
            unsigned int resultEval = figure->eval(dicesOccurences);

            std::cout << "\t" << index << ": "
                << "\t" << std::setw(10) << std::left
                << figure->name<< " : " 
                << resultEval
                << std::endl;
        }
    }
}

void Yahtzee::joueur::makeChoice()
{
    std::cout 
        << "\n*******************************************\n"
        << "Faites votre choix par indice (ex. 4) : ";

    unsigned int choice = getIntInput() - 1;

    std::shared_ptr<figure> choosenFigure = figures.at(choice);

    choosenFigure->playerPoints = choosenFigure->currentPoints;
    choosenFigure->used = true;

    if (std::dynamic_pointer_cast<figureSuperieur>(choosenFigure) != nullptr) {
        this->totalSup += choosenFigure->currentPoints;
        if (totalSup >= 63) {
            totalSup += 35;
            std::cout
                << "*********************************************************************************\n"
                << "*************************** PRIME OBTENU (+35 points) ***************************\n"
                << "*********************************************************************************\n";
        }
    }
    else {
        this->totalInf += choosenFigure->currentPoints;

    }

    // reset figures
    for (std::shared_ptr<figure> figure : figures) {
        if (!figure->isUsed()) {
            figure->currentPoints = 0;
        }
    }

}

unsigned int Yahtzee::joueur::getIntInput() const 
{
    std::string strChoice;
    strChoice = getChoice();
    //std::getline(std::cin, strChoice);
    unsigned int input;
    
    try {

        input = extractInts(strChoice).at(0);
    }
    catch (std::exception e) {
        std::cout << "\nSaisir une valeur entiere (indice) : ";
        return getIntInput();
    }

    if (input < 1 || input > figures.size()) {
        std::cout << "\nSaisir une valeur entiere entre 1 et " << figures.size() <<" : ";
        return getIntInput();

    }
    
    return input;
}

unsigned int Yahtzee::joueur::getTotalPoints() const
{
    return totalInf + totalSup;
}

bool Yahtzee::joueur::hasFinished() const
{
    // si il y a encore une figure non utilisee, alors le joueur n'a pas fini
    for (std::shared_ptr<figure> figure : figures) {
        if (!figure->isUsed()) {
            return false;
        }
    }
    return true;
}

std::vector<unsigned int> Yahtzee::joueur::extractInts(std::string str) const
{
    std::vector<unsigned int> choices;
    std::stringstream ss;

    ss << str;

    std::string temp;
    unsigned int found;
    while (!ss.eof()) {

        ss >> temp;

        if (std::stringstream(temp) >> found)
            choices.push_back(found);

        temp = "";

    }

    return choices;
    return { 1, 2 };
}

