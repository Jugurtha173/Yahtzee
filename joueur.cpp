#include "joueur.h"
#include <iomanip>

Yahtzee::joueur::joueur(std::string name, lancer* roll, std::vector<figure*> figures) :
    name(name), roll(roll), figures(figures)
{

};


void Yahtzee::joueur::play() const 
{
	std::string strChoices;
	for ( unsigned int i = 1; i <= nbrTurns; ++i) {
        std::cout << "\n";

        // lancer les des
		roll->rollDices();

        // evaluation des figures
        allFiguresEval();

        if (i < nbrTurns) {
            // hold
            std::cout << "Selectionez les indices des des a GARDER (ex. 1 3 5) : ";
            std::getline(std::cin, strChoices);
            std::vector<unsigned int> holdIndexes = extractInts(strChoices);
            roll->holdDicesByIndex(holdIndexes);
            /*
            // unhold
            std::cout << "Selectionez les indices des des a RELACHER (ex. 1 3 5) : ";
            std::getline(std::cin, strChoices);
            std::vector<unsigned int> unholdIndexes = extractInts(strChoices);
            roll->unholdDicesByIndex(unholdIndexes);
            */
        }
        


        
	}
    makeChoice();
}

void Yahtzee::joueur::allFiguresEval() const
{
    std::cout << "Ce que vous pouvez avoir : \n";
    int index = 0;
    for (figure* figure : figures) {
        ++index;
        if (!figure->isUsed()) {
            std::cout << "\t" << index << ": "
                << "\t" << std::setw(10) << std::left 
                << figure->name<< " : " 
                << figure->eval(roll) 
                << std::endl;
        }
    }
}

void Yahtzee::joueur::makeChoice() const
{
    std::cout << "Faites votre choix (ex. 1 3 5) : ";

    unsigned int choice = getIntInput() - 1;

    figures.at(choice)->playerPoints = figures.at(choice)->currentPoints;
    figures.at(choice)->used = true;

    // reset figures
    for (figure* figure : figures) {
        if (!figure->isUsed()) {
            figure->currentPoints = 0;
        }
    }

}

unsigned int Yahtzee::joueur::getIntInput() const 
{
    std::string strChoice;
    std::getline(std::cin, strChoice);
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

bool Yahtzee::joueur::hasFinished() const
{
    // si il y a encore une figure non utilisee, alors le joueur n'a pas fini
    for (figure* figure : figures) {
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

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    std::string temp;
    unsigned int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (std::stringstream(temp) >> found)
            choices.push_back(found);

        /* To save from space at the end of string */
        temp = "";

    }

    return choices;
}

