// Jugurtha ASMA && Hylia BOUDAHBA

#include "joueur.h"
#include "figuresJeu.h"
#include <iomanip>

Yahtzee::joueur::joueur(std::string name, lancerPtr roll)
    : name(name), roll(roll), figures(figuresJeu::getFigures()) {};

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

            strChoices = chooseDicesToRoll(); // std::getline(std::cin, strChoices);
            if (strChoices.empty()) break;
            std::vector<unsigned int> indexes = extractInts(strChoices);
            roll->rollDices(indexes);
        }
	}
}

std::string Yahtzee::joueur::chooseDicesToRoll() const
{
    std::string strChoices;
    std::getline(std::cin, strChoices);
    return strChoices;
}

Yahtzee::figurePtr Yahtzee::joueur::chooseFigure() const
{
    std::string strChoice;
    std::getline(std::cin, strChoice);

    for (figurePtr figure : figures) {
        if (figure->name.find(strChoice) != std::string::npos) {
            if (!figure->isUsed()) {
                return figure;
            }
            else {
                std::cout << "Choisir une figure diponible : ";
                return chooseFigure();
            }
        }
    }

    std::cout << "Choisir une figure existante : ";
    return chooseFigure();
}

void Yahtzee::joueur::evalFigures() const
{
    // lancer les des
    std::vector<unsigned int> dicesOccurences = roll->getDicesOccurences();

    std::cout << "Ce que vous pouvez avoir : \n";
    int index = 0;
    for (figurePtr figure : figures) {
        ++index;
        if (!figure->isUsed()) {
            figure->currentPoints = figure->eval(dicesOccurences);

            std::cout
                << "\t" << std::setw(10) << std::left
                << figure->name<< " : " 
                << figure->currentPoints
                << std::endl;
        }
    }
}

void Yahtzee::joueur::makeChoice()
{
    std::cout 
        << "\n*******************************************\n"
        << "Faites votre choix par le nom exacte des figures ci-dessus (ex. Petite S) : ";

    figurePtr choosenFigure = chooseFigure();

    choosenFigure->playerPoints = choosenFigure->currentPoints;
    choosenFigure->used = true;

    if (std::dynamic_pointer_cast<figureSuperieur>(choosenFigure) != nullptr) {
        this->totalSup += choosenFigure->playerPoints;
        if (totalSup >= 63) {
            totalSup += 35;
            std::cout
                << "*********************************************************************************\n"
                << "*************************** PRIME OBTENU (+35 points) ***************************\n"
                << "*********************************************************************************\n";
        }
    }
    else {
        this->totalInf += choosenFigure->playerPoints;
    }

    // reset all figures
    for (figurePtr figure : figures) {
        if (!figure->isUsed()) {
            figure->currentPoints = 0;
        }
    }
}

unsigned int Yahtzee::joueur::getTotalPoints() const
{
    return totalInf + totalSup;
}

std::string Yahtzee::joueur::getName() const
{
    return name;
}

std::vector<Yahtzee::figurePtr> Yahtzee::joueur::getFigures() const 
{
    return figures;
}

bool Yahtzee::joueur::hasFinished() const
{
    // si il y a encore une figure non utilisee, alors le joueur n'a pas fini
    for (figurePtr figure : figures) {
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
}

std::ostream& Yahtzee::operator<<(std::ostream& out, const joueur& player)
{
    return out << player.name << " (" << player.getTotalPoints() << ")";
}
