#pragma once


#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "de.h"

namespace Yahtzee {

	class lancer
	{
		unsigned int numberOfFaces = 6;
		unsigned int numberOfDices = 5;
		std::vector<de*> dices;


		void sortDices();

	public:
		lancer();
		~lancer();

		std::vector<de*>& getDices() { return dices; };
		std::vector<unsigned int> getDicesOccurences() const ;

		std::vector<unsigned int> rollDices() ;
		void holdDicesByIndex(const std::vector<unsigned int>& indexes, bool hold = true); // hold ba default
		void unholdDicesByIndex(const std::vector<unsigned int>& indexes);
		void unholdAll();

		void showDices() const ;

		friend class figure;

	};

}


