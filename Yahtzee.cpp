
#include <iostream>
#include <iomanip>
#include <vector>

#include "partie.h"


void clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

using namespace Yahtzee;

int main()
{

    char cpt = 0;

    cpt++; cpt++;

    std::cout << sizeof(char) << std::endl;

    
   partie game;

   game.launch();
   

    return 0;
}
