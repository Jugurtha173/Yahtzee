// Jugurtha ASMA && Hylia BOUDAHBA

#include "figure.h"

const std::string Yahtzee::figure::getName()
{
    return name;
}

bool Yahtzee::figure::isUsed()
{
    return used;
}

void Yahtzee::figure::setChoose()
{
    used = true;
}

bool Yahtzee::figure::operator<=(const figure& figure)
{
    return currentPoints <= figure.currentPoints;
}

std::ostream& Yahtzee::operator<<(std::ostream& out, const figure& figure)
{
    return out << (figure.playerPoints == -1 ? "_" : std::to_string(figure.playerPoints));
}
