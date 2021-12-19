// Jugurtha ASMA && Hylia BOUDAHBA

#include <iostream>
#include <iomanip>
#include <vector>
#include "partie.h"

using namespace Yahtzee;

int main()
{    
    partie* game = new partie(6);
    game->launch();
    delete game;
    
    return 0;
}
